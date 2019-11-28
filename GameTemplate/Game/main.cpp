#include "stdafx.h"
#include "system/system.h"
#include "Player.h"
#include "Enemy.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "level/Level.h"

///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");

	//�J�������������B
	/*g_camera3D.SetPosition({ 0.0f, 300.0f, 500.0f });
	g_camera3D.SetTarget({ 0.0f, 100.0f, 0.0f });
	g_camera3D.SetFar(10000.0f);*/
	//�v���C���[
	Player player;
	player.SetPosition({ 00.0f,0.0f,-1000.0f });
	//�Q�[���J����
	GameCamera gamecamera;
	gamecamera.SetPlayer(&player);
	//�w�i
	BackGround background;
	//���x��
	Level m_level;
	std::vector< Enemy* > enemyList;
	//���x�����������B
	m_level.Init(L"Assets/level/rouka.tkl", [&](LevelObjectData& objData) {
		if (objData.EqualName(L"enemy") == true) {
			//Star�B
			auto enemy = new Enemy(objData.position, objData.rotation, &player);
			enemyList.push_back(enemy);
			return true;
		}
		return false;
	});
	//�Q�[�����[�v�B
	while (DispatchWindowMessage() == true)
	{
		//�`��J�n�B
		g_graphicsEngine->BegineRender();
		//�Q�[���p�b�h�̍X�V�B	
		for (auto& pad : g_pad) {
			pad.Update();
		}
		//�����G���W���̍X�V�B
		g_physics.Update();
		//�v���C���[�̍X�V�B
		player.Update();
		for (auto& enemy : enemyList) {
			enemy->Update();
		}
		gamecamera.Update();
		background.Update();
		//�v���C���[�̕`��B
		player.Draw();
		//���x����`��
		m_level.Draw();
		//�G�l�~�[��`��
		for (auto& enemy : enemyList) {
			enemy->Draw();
		}
		background.Draw();
		//�J�����̍X�V�B
		g_camera3D.Update();
		//�`��I���B
		g_graphicsEngine->EndRender();
	}
}