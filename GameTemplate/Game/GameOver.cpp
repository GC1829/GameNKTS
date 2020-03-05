#include "stdafx.h"
#include "GameOver.h"
#include "Game.h"


GameOver::GameOver()
{
}


GameOver::~GameOver()
{
}

void GameOver::Update()
{
	m_sprite.UpdateWorldMatrix(CVector3::Zero(), CQuaternion::Identity(), CVector3::One());
}

void GameOver::Render()
{
	CMatrix mView;
	CMatrix mProj;
	mView.MakeLookAt(
		{ 0,0,1 },
		{ 0,0,0 },
		{ 0,1,0 }
	);
	mProj.MakeOrthoProjectionMatrix(1280, 720, 0.1, 100);
	m_sprite.Draw(mView, mProj);
}