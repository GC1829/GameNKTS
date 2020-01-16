#include "stdafx.h"
#include <iostream>
#include "Game.h"
#include "GameObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "GameCamera.h"
#include "BackGround.h"


Game* g_game = nullptr;

Game::Game()
{
	g_game = this;
	m_sprite.Init(L"Assets/Sprite/robot.dds", 1200, 200);
	m_soundEngine.Init();

	m_bgm.Init(L"Assets/sound/noroinouta.wav");
	m_bgm.Play(true);

	//レベルを初期化。
	m_level.Init(L"Assets/level/School.tkl", [&](LevelObjectData& objData) {
		if (objData.EqualName(L"enemy") == true) {
			//Star。
			auto enemy = new Enemy(objData.position, objData.rotation, &m_player);
			enemyList.push_back(enemy);
			return true;
		}
		return false;
	});

	m_player.SetPosition({ -400.0f,0.0f,800.0f });

	InitTranslucentBlendState();
	m_camera.SetPlayer(&m_player);
	
}


Game::~Game()
{

	g_game = nullptr;

	for (auto& enemy : enemyList) {
		delete enemy;
	}
}

void Game::InitTranslucentBlendState()
{
	CD3D11_DEFAULT defaultSettings;

	CD3D11_BLEND_DESC blendDesc(defaultSettings);
	//aブレンディングを有効にする。
	blendDesc.RenderTarget[0].BlendEnable = true;

	//ソースカラーのブレンディング方法を指定している。
}

void Game::Update()
{
	//プレイヤーの更新。
	m_player.Update();
	for (auto& enemy : enemyList) {
		enemy->Update();
	}
	m_soundEngine.Update();
	m_camera.Update();
	m_sprite.UpdateWorldMatrix(CVector3::Zero(), CQuaternion::Identity(), CVector3::One());
}

void Game::Draw()
{

}

void Game::Render()
{
	CMatrix mView;
	CMatrix mProj;
	mView.MakeLookAt(
		{ 0,0,1 },
		{ 0, 0, 0 },
		{ 0,1,0 }
	);
	mProj.MakeOrthoProjectionMatrix(1280, 720, 0.1, 100);
	m_sprite.Draw(mView, mProj);

	//プレイヤーの描画。
	m_player.Draw();
	//レベルを描画
	m_level.Draw();
	//エネミーを描画
	for (auto& enemy : enemyList) {
		enemy->Draw();
	}
}