#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/unityChan.cmo", enFbxUpAxisY);
	
	//tkaファイルの読み込み。
	m_animationClips[0].Load(L"Assets/animData/walk.tka");
	m_animationClips[0].SetLoopFlag(true);

	m_animationClips[1].Load(L"Assets/animData/run.tka");
	m_animationClips[1].SetLoopFlag(true);


	m_animation.Init(
		m_model,			//アニメーションを流すスキンモデル。
							//これでアニメーションとスキンモデルが関連付けされる。
		m_animationClips,	//アニメーションクリップの配列。
		2					//アニメーションクリップの数。
	);
	m_position.y = 100.0f;
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
	m_movespeed.x = g_pad[0].GetLStickXF() * 400.0f;
	m_movespeed.z = g_pad[0].GetLStickYF() * 400.0f;
	m_position = m_characon.Execute(1.0f / 60.0f, m_movespeed);
	//ワールド行列の更新。
	m_animation.Update(1.0f / 30.0f);
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);
}
void Player::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(), 
		g_camera3D.GetProjectionMatrix()
	);
}