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
	////プレイヤー
	//Player player;
	//player.SetPosition({ 00.0f,0.0f,-1000.0f });
	////ゲームカメラ
	//GameCamera gamecamera;
	//gamecamera.SetPlayer(&player);
	////背景
	//BackGround background;
	////レベル
	//Level m_level;
	//std::vector< Enemy* > enemyList;
	////レベルを初期化。
	//m_level.Init(L"Assets/level/rouka.tkl", [&](LevelObjectData& objData) {
	//	if (objData.EqualName(L"enemy") == true) {
	//		//Star。
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
	////プレイヤーの更新。
	//player.Update();
	//for (auto& enemy : enemyList) {
	//	enemy->Update();
	//}
	//gamecamera.Update();
	//background.Update();
}

void Game::Draw()
{
	////プレイヤーの描画。
	//player.Draw();
	////レベルを描画
	//m_level.Draw();
	////エネミーを描画
	//for (auto& enemy : enemyList) {
	//	enemy->Draw();
	//}
	//background.Draw();
}