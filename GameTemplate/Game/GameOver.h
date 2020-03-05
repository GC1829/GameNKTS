#pragma once
#include "GameObjectManager.h"
#include "Sprite.h"

class GameOver : public IGameObject
{
public:
	GameOver();
	~GameOver();
	void Update();
	void Render();
private:
	Sprite m_sprite;
};

extern GameOver* g_gameover;