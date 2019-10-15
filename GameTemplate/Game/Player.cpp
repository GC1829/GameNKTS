#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	//cmo�t�@�C���̓ǂݍ��݁B
	m_model.Init(L"Assets/modelData/unityChan.cmo");
	m_characon.Init(
		30.0f,
		100.0f,
		m_position
	);
}


Player::~Player()
{
}

void Player::Update()
{
	m_movespeed.x = g_pad[0].GetLStickXF() * 200.0f;
	m_movespeed.z = g_pad[0].GetLStickYF() * 200.0f;
	
	//m_position = m_characon.Execute(1.0f / 60.0f, m_movespeed);
	//���[���h�s��̍X�V�B

	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);
	
}
void Player::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(), 
		g_camera3D.GetProjectionMatrix()
	);
}