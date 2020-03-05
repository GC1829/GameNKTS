#include "stdafx.h"
#include "Title.h"
#include "Game.h"

Title* g_title = nullptr;

Title::Title()
{
	m_sprite.Init(L"Assets/Sprite/Title.dds", 1600, 2400);
}


Title::~Title()
{

}
void Title::Update()
{
	if (g_pad[0].IsPress(enButtonA) == true) {
		g_goMgr.NewGO<Game>();
		g_goMgr.DeleteGO(this);
	}

	m_sprite.UpdateWorldMatrix(CVector3::Zero(), CQuaternion::Identity(), CVector3::One());
}
void Title::Render()
{
	CMatrix mView;
	CMatrix mProj;
	mView.MakeLookAt(
		{0,0,1},
		{0,0,0},
		{0,1,0}
	);
	mProj.MakeOrthoProjectionMatrix(1280, 720, 0.1, 100);
	m_sprite.Draw(mView, mProj);
}