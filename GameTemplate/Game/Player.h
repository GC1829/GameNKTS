#pragma once
#include "GameObjectManager.h"
#include "character/CharacterController.h"
#include "SoundEngin.h"
#include "SoundSouce.h"

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
		m_characon.SetPosition(m_position);
	}
	CVector3 GetPosition()
	{
		return m_position;
	}
private:
	SoundEngine m_soundEngine;
	SkinModel m_model;	//スキンモデル。
	Animation m_animation;
	AnimationClip m_animationClips[2];
	CVector3 m_position = CVector3::Zero();
	Player* m_player;
	CQuaternion m_rotation = CQuaternion::Identity();
	CVector3 m_scale = CVector3::One();
	CVector3 m_movespeed = CVector3::Zero();
	CharacterController m_characon;
	SoundSource m_bgm;
};

