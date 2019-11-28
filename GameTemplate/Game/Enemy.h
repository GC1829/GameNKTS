#pragma once
#include "character/CharacterController.h"
#include "GameObjectManager.h"
class Player;

class Enemy
{
public:
	Enemy(CVector3 pos, CQuaternion rot, Player* player);
	~Enemy();
	void Update();
	void Draw();
	void SetPosition(const CVector3& pos)
	{
		m_position = pos;
	}
private:
	bool IsFind();
	void Update_Follow();
	void Nomal();
	void Turn();
private:
	enum EnState {
		enState_Follow,
		enState_Nomal,
		enState_Turn
	};
	SkinModel m_model;	//スキンモデル。
	CVector3 m_position = CVector3::Zero();
	CVector3 m_old = CVector3::Zero();
	CVector3 m_ReturnPos = CVector3::Zero();
	Player* m_player = nullptr;
	CQuaternion m_rotation = CQuaternion::Identity();
	CVector3 m_scale = CVector3::One();
	CVector3 m_movespeed = CVector3::Zero();
	EnState m_state = enState_Nomal;
};

