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
	float FollowPlayer = 450.0f;							//プレイヤー追従
	float FindPlayer = 400.0f;							//プレイヤー発見
	float PositionUp = 100.0f;
	SkinModel m_model;									//スキンモデル。
	CVector3 m_position = CVector3::Zero();				//座標
	CVector3 m_old = CVector3::Zero();					//古い座標
	CVector3 m_ReturnPos = CVector3::Zero();			//帰還パス
	Player* m_player = nullptr;							//プレイヤー
	CQuaternion m_rotation = CQuaternion::Identity();	//回転
	CVector3 m_scale = CVector3::One();					//スケール
	CVector3 m_movespeed = CVector3::Zero();			//移動速度
	EnState m_state = enState_Nomal;					//ステート
};

