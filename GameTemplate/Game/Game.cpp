#include "stdafx.h"
#include <iostream>
#include "Game.h"
#include "GameObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "GameCamera.h"
#include "BackGround.h"

Game::Game()
{
	////�v���C���[
	//Player player;
	//player.SetPosition({ 00.0f,0.0f,-1000.0f });
	////�Q�[���J����
	//GameCamera gamecamera;
	//gamecamera.SetPlayer(&player);
	////�w�i
	//BackGround background;
	////���x��
	//Level m_level;
	//std::vector< Enemy* > enemyList;
	////���x�����������B
	//m_level.Init(L"Assets/level/rouka.tkl", [&](LevelObjectData& objData) {
	//	if (objData.EqualName(L"enemy") == true) {
	//		//Star�B
	//		auto enemy = new Enemy(objData.position, objData.rotation, &player);
	//		enemyList.push_back(enemy);
	//		return true;
	//	}
	//	return false;
	//});
}


Game::~Game()
{

}

void Game::Update()
{
	////�v���C���[�̍X�V�B
	//player.Update();
	//for (auto& enemy : enemyList) {
	//	enemy->Update();
	//}
	//gamecamera.Update();
	//background.Update();
}

void Game::Draw()
{
	////�v���C���[�̕`��B
	//player.Draw();
	////���x����`��
	//m_level.Draw();
	////�G�l�~�[��`��
	//for (auto& enemy : enemyList) {
	//	enemy->Draw();
	//}
	//background.Draw();
}