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
	float FollowPlayer = 450.0f;							//�v���C���[�Ǐ]
	float FindPlayer = 400.0f;							//�v���C���[����
	float PositionUp = 100.0f;
	SkinModel m_model;									//�X�L�����f���B
	CVector3 m_position = CVector3::Zero();				//���W
	CVector3 m_old = CVector3::Zero();					//�Â����W
	CVector3 m_ReturnPos = CVector3::Zero();			//�A�҃p�X
	Player* m_player = nullptr;							//�v���C���[
	CQuaternion m_rotation = CQuaternion::Identity();	//��]
	CVector3 m_scale = CVector3::One();					//�X�P�[��
	CVector3 m_movespeed = CVector3::Zero();			//�ړ����x
	EnState m_state = enState_Nomal;					//�X�e�[�g
};

