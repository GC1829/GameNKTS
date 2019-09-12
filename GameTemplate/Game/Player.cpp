#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	//cmoファイルの読み込み。
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
	//ワールド行列の更新。
	m_model.UpdateWorldMatrix(CVector3::Zero(), CQuaternion::Identity(), CVector3::One());
	m_movespeed.x += Pad().GetLStickXF() * 500.0f;
	m_movespeed.z += Pad().GetLStickYF() * 500.0f;
}
void Player::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(), 
		g_camera3D.GetProjectionMatrix()
	);
}