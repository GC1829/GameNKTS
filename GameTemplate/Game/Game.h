#pragma once
#include "GameObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "level/Level.h"
#include "SoundEngin.h"
#include "SoundSouce.h"

class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	void Draw();
	void Render();
private:
	SoundEngine m_soundEngine;
	Player m_player;
	GameCamera m_camera;
	Level m_level;
	BackGround m_ground;
	std::vector<Enemy*> enemyList;
	SoundSource m_bgm;
};

extern Game* g_game;
