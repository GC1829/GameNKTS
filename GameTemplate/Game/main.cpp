#include "stdafx.h"
#include "system/system.h""
#include "Game.h"
#include "GameObjectManager.h"
#include "SoundEngin.h"

using namespace std;

void UpdateGame()
{
	//ゲームパッドの更新。	
	for (auto& pad : g_pad) {
		pad.Update();
	}
	g_goMgr.Update();
	//物理エンジンの更新。
	g_physics.Update();
}

void RenderGame()
{
	//描画開始。
		g_graphicsEngine->BegineRender();
		g_goMgr.Update();
	//描画終了。
		g_graphicsEngine->EndRender();
}
///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//ゲームの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");
	g_goMgr.NewGO<Game>();
	//ゲームループ。
	while (DispatchWindowMessage() == true)
	{
		UpdateGame();

		RenderGame();
	}
}