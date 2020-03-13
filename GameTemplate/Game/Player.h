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
	//ダメージ判定
	void Damage();
	//プレイヤーのポジションを設定する。
	void SetPosition(const CVector3& pos)
	{
		m_position = pos;
		m_characon.SetPosition(m_position);
	}
	//プレイヤーのポジションを受け取る
	CVector3 GetPosition()
	{
		return m_position;
	}
	
private:
	SkinModel m_model;									//スキンモデル。
	Animation m_animation;								//アニメージョン
	AnimationClip m_animationClips[2];					//アニメーションクリップ
	CVector3 m_position = CVector3::Zero();				//ポジション
	Player* m_player;									//プレイヤー
	Enemy* m_enemy = nullptr;							//エネミー
	//float HP = 10;
	bool m_isDead = false;								//死亡フラグ
	CQuaternion m_rotation = CQuaternion::Identity();	//回転
	CVector3 m_scale = CVector3::One();					//拡大
	CVector3 m_movespeed = CVector3::Zero();			//移動速度
	CharacterController m_characon;						//キャラコン
	Sprite m_sprite;									//画像
	int m_enelisNo = 0;
};

