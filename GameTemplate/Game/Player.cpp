#include "stdafx.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"


Player::Player()
{

	//cmo�t�@�C���̓ǂݍ��݁B
	m_model.Init(L"Assets/modelData/unityChan.cmo", enFbxUpAxisZ);
	
	//tka�t�@�C���̓ǂݍ��݁B
	m_animationClips[0].Load(L"Assets/animData/walk.tka");
	m_animationClips[0].SetLoopFlag(true);

	m_animationClips[1].Load(L"Assets/animData/run.tka");
	m_animationClips[1].SetLoopFlag(true);


	m_animation.Init(
		m_model,			//�A�j���[�V�����𗬂��X�L�����f���B
							//����ŃA�j���[�V�����ƃX�L�����f�����֘A�t�������B
		m_animationClips,	//�A�j���[�V�����N���b�v�̔z��B
		2					//�A�j���[�V�����N���b�v�̐��B
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
	std::vector<Enemy*>& enelist = g_game->GetEnemyList();
	for (int i = 1; i <= enelist.size(); i++) {
		CVector3 toEnemy = enelist[i]->GetEnePosition() - m_position;
		float len = toEnemy.Length();
		//���K��
		toEnemy.Normalize();
		if (len <= 50.0f)
		{
			m_isDead = true;	//���S����
		}
	}
		//m_enemy->GetPosition() - m_position;
		//float len = toEnemy.Length();
		////���K��
		//toEnemy.Normalize();
	}
void Player::Update()
{
	Damage();
	if (m_movespeed.x = g_pad[0].GetLStickXF() * -700.0f)
	{
		//m_animation.Update(1.0f / 30.0f);
	}
	if (m_movespeed.z = g_pad[0].GetLStickYF() * -700.0f)
	{
		//m_animation.Update(1.0f / 30.0f);
	}
	m_position = m_characon.Execute(1.0f / 60.0f, m_movespeed);

	//�����̕ύX
	if (fabsf(m_movespeed.x) > 0.1f || fabsf(m_movespeed.z) > 0.1f) {
		m_rotation.SetRotation(CVector3::AxisY(), atan2f(m_movespeed.x, m_movespeed.z));
	}
	//���[���h�s��̍X�V�B
	//m_animation.Update(1.0f / 30.0f);
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);
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