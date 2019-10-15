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
	void SetPosition(const CVector3& pos)
	{
		m_position = pos;
	}
private:
	SkinModel m_model;	//スキンモデル。
	CVector3 m_position = CVector3::Zero();
	Player* m_player;
	CQuaternion m_rotation = CQuaternion::Identity();
	CVector3 m_scale = CVector3::Zero();
	CVector3 m_movespeed = CVector3::Zero();
	CharacterController m_characon;
};

