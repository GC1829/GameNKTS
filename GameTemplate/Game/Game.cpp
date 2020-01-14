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

	//���x�����������B
	m_level.Init(L"Assets/level/rouka.tkl", [&](LevelObjectData& objData) {
		if (objData.EqualName(L"enemy") == true) {
			//Star�B
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
	//�v���C���[�̍X�V�B
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
	//�v���C���[�̕`��B
	m_player.Draw();
	//���x����`��
	m_level.Draw();
	//�G�l�~�[��`��
	for (auto& enemy : enemyList) {
		enemy->Draw();
	}
}