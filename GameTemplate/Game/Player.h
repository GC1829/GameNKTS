#pragma once
#include "GameObjectManager.h"
#include "character/CharacterController.h"

class Player
{
public:
	Player();
	~Player();
	void Update();
	void Draw();
private:
	SkinModel m_model;	//スキンモデル。
	CVector3 m_position;
	Player* m_player;
	CQuaternion m_rotation;
	CVector3 m_scale;
	CVector3 m_movespeed;
	CharacterController m_characon;

};

