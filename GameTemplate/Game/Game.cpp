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

	m_soundEngine.Init();

	m_bgm.Init(L"Assets/sound/noroinouta.wav");
	m_bgm.Play(true);

	//レベルを初期化。
	m_level.Init(L"Assets/level/rouka.tkl", [&](LevelObjectData& objData) {
		if (objData.EqualName(L"enemy") == true) {
			//Star。
			auto enemy = new Enemy(objData.position, objData.rotation, &m_player);
			enemyList.push_back(enemy);
			return true;
		}
		return false;
	});

	m_player.SetPosition({ 00.0f,0.0f,-1000.0f });


	m_camera.SetPlayer(&m_player);
	
}


Game::~Game()
{

	g_game = nullptr;

	for (auto& enemy : enemyList) {
		delete enemy;
	}
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

}

void Game::Draw()
{

}

void Game::Render()
{
	//プレイヤーの描画。
	m_player.Draw();
	//レベルを描画
	m_level.Draw();
	//エネミーを描画
	for (auto& enemy : enemyList) {
		enemy->Draw();
	}
}