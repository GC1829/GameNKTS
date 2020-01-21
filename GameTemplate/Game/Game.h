#pragma once
#include "GameObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "level/Level.h"
#include "SoundEngin.h"
#include "SoundSouce.h"
#include "Sprite.h"

class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	void Draw();
	void Render();
private:
	/// <summary>
	/// 半透明合成のブレンドステートを初期化
	/// </summary>
	void InitTranslucentBlendState();
private:
	SoundEngine m_soundEngine;
	Player m_player;
	Sprite m_sprite;
	GameCamera m_camera;
	Level m_level;
	BackGround m_ground;
	std::vector<Enemy*> enemyList;
	SoundSource m_bgm;
	ID3D11BlendState* m_translucentBlendState = nullptr;
};
extern Game* g_game;
