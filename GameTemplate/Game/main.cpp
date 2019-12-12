#include "stdafx.h"
#include "system/system.h""
#include "Game.h"
#include "GameObjectManager.h"
#include "SoundEngin.h"

using namespace std;

void UpdateGame()
{
	//�Q�[���p�b�h�̍X�V�B	
	for (auto& pad : g_pad) {
		pad.Update();
	}
	g_goMgr.Update();
	//�����G���W���̍X�V�B
	g_physics.Update();
}

void RenderGame()
{
	//�`��J�n�B
		g_graphicsEngine->BegineRender();
		g_goMgr.Update();
	//�`��I���B
		g_graphicsEngine->EndRender();
}
///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");
	g_goMgr.NewGO<Game>();
	//�Q�[�����[�v�B
	while (DispatchWindowMessage() == true)
	{
		UpdateGame();

		RenderGame();
	}
}