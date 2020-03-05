#include "stdafx.h"
#include "Player.h"
#include "Enemy.h"


Player::Player()
{

	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/unityChan.cmo", enFbxUpAxisZ);
	
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

void Player::Damage()
{
	CVector3 toEnemy = m_enemy->GetPosition() - m_position;
	float len = toEnemy.Length();
	//正規化
	toEnemy.Normalize();
	if (len <= 50.0f)
	{
		m_isDead = true;	//死亡判定
	}
}
void Player::Update()


{
	if (m_movespeed.x = g_pad[0].GetLStickXF() * -700.0f)
	{
		//m_animation.Update(1.0f / 30.0f);
	}
	if (m_movespeed.z = g_pad[0].GetLStickYF() * -700.0f)
	{
		//m_animation.Update(1.0f / 30.0f);
	}
	m_position = m_characon.Execute(1.0f / 60.0f, m_movespeed);

	//向きの変更
	if (fabsf(m_movespeed.x) > 0.1f || fabsf(m_movespeed.z) > 0.1f) {
		m_rotation.SetRotation(CVector3::AxisY(), atan2f(m_movespeed.x, m_movespeed.z));
	}
	//ワールド行列の更新。
	//m_animation.Update(1.0f / 30.0f);
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);

	/*if (m_position.x == -400.0f)
	{
		m_bgm.Init(L"Assets/sound/himei.wav");
		m_bgm.Play(true);
	}*/
	if (m_isDead == true)
	{
		m_sprite.Init(L"Assets/Sprite/GameOver.dds", 1600, 2400);
	}
}
void Player::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(), 
		g_camera3D.GetProjectionMatrix()
	);
}