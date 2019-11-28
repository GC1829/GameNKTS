#pragma once
#include "GameObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "level/Level.h"

class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	void Draw();
};

