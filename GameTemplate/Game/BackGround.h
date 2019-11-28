#pragma once
#include "physics/PhysicsStaticObject.h"
#include "GameObjectManager.h"
class BackGround
{
public:
	BackGround();
	~BackGround();
	void Update();
	void Draw();
private:
	SkinModel m_model;
	PhysicsStaticObject m_phyStaticObject;
};