#pragma once
#include "GameObjectManager.h"
#include "character/CharacterController.h"
#include "Sprite.h"
class Enemy;

class Player
{
public:
	Player();
	~Player();
	void Update();
	void Draw();
	//�_���[�W����
	void Damage();
	//�v���C���[�̃|�W�V������ݒ肷��B
	void SetPosition(const CVector3& pos)
	{
		m_position = pos;
		m_characon.SetPosition(m_position);
	}
	//�v���C���[�̃|�W�V�������󂯎��
	CVector3 GetPosition()
	{
		return m_position;
	}
	
private:
	SkinModel m_model;									//�X�L�����f���B
	Animation m_animation;								//�A�j���[�W����
	AnimationClip m_animationClips[2];					//�A�j���[�V�����N���b�v
	CVector3 m_position = CVector3::Zero();				//�|�W�V����
	Player* m_player;									//�v���C���[
	Enemy* m_enemy = nullptr;							//�G�l�~�[
	//float HP = 10;
	bool m_isDead = false;								//���S�t���O
	CQuaternion m_rotation = CQuaternion::Identity();	//��]
	CVector3 m_scale = CVector3::One();					//�g��
	CVector3 m_movespeed = CVector3::Zero();			//�ړ����x
	CharacterController m_characon;						//�L�����R��
	Sprite m_sprite;									//�摜
	int m_enelisNo = 0;
};

