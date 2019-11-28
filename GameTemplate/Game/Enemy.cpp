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

void Enemy::Update()
{
	if (state == 0) {
		CVector3 toPlayerDir = m_player->GetPosition() - m_position;
		float len = toPlayerDir.Length();
		toPlayerDir.Normalize();
		if (len < 400.0f) {

			//m_position += toPlayer *= 5.0f;
			state = 1;
		}
		if (state == 1) {
			CVector3 toPlayer = m_player->GetPosition() - m_position;
			//float len = toPlayer.Length();
			toPlayer.Normalize();
			m_position += toPlayer * 5.0f;
		}
		if (state == 2)
		{

		}
	}
	m_rotation.SetRotation(CVector3::AxisY(), atan2f(m_rotation.x, m_rotation.z));

	//向きの変更
	//m_rotation.SetRotation(CVector3::AxisY(), atan2f(m_movespeed.x, m_movespeed.z));
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);
}

void Enemy::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}