#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(CVector3 pos, CQuaternion rot, Player* player) :
	m_position(pos),
	m_rotation(rot),  
	m_player(player)
{
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/enemy.cmo");
}


Enemy::~Enemy()
{
}

bool Enemy::IsFind()
{
	CVector3 toPlayerDir = m_player->GetPosition() - m_position;
	float len = toPlayerDir.Length();
	//正規化
	toPlayerDir.Normalize();
	if (len < 400.0f) {
		return true;
	}
	return false;
}

void Enemy::Nomal()
{
	if (IsFind() == true) {
		//プレイヤーを発見
		//プレイヤーの追従処理
		m_state = enState_Follow;
	}
}

void Enemy::Update_Follow()
{
	CVector3 toPlayer = m_player->GetPosition() - m_position;
	float len = toPlayer.Length();
	toPlayer.Normalize();
	m_position += toPlayer * 6.0f;

	if (len > 450.0f)
	{
		Turn();
	}
}

void Enemy::Turn()
{
	m_old.y = 100.0f;
	m_position = m_old;
}

void Enemy::Update()
{
	switch (m_state)
	{
	case Enemy::enState_Follow:
		Update_Follow();
		break;
	case Enemy::enState_Nomal:
		Nomal();
		break;
	case Enemy::enState_Turn:
		Turn();
		break;
	}
	m_rotation.SetRotation(CVector3::AxisY(), atan2f(m_rotation.x, m_rotation.z));

	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);
}

void Enemy::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}