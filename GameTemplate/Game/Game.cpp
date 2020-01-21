#include "stdafx.h"
#include <iostream>
#include "Game.h"
#include "GameObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "GameCamera.h"
#include "BackGround.h"


Game* g_game = nullptr;

Game::Game()
{
	g_game = this;
	m_sprite.Init(L"Assets/Sprite/robot.dds",1200, 1200);
	m_soundEngine.Init();

	//m_bgm.Init(L"Assets/sound/noroinouta.wav");
	//m_bgm.Play(true);

	////���x�����������B
	//m_level.Init(L"Assets/level/School.tkl", [&](LevelObjectData& objData) {
	//	if (objData.EqualName(L"enemy") == true) {
	//		//Star�B
	//		auto enemy = new Enemy(objData.position, objData.rotation, &m_player);
	//		enemyList.push_back(enemy);
	//		return true;
	//	}
	//	return false;
	//});

	//m_player.SetPosition({ -400.0f,0.0f,800.0f });

	InitTranslucentBlendState();
	m_camera.SetPlayer(&m_player);
	
}


Game::~Game()
{

	g_game = nullptr;

	for (auto& enemy : enemyList) {
		delete enemy;
	}
	if (m_translucentBlendState != nullptr) {
		m_translucentBlendState->Release();
	}
}

void Game::InitTranslucentBlendState()
{
	//��̂��Ƃ��A�쐬����u�����h�X�e�[�g�̏���ݒ肷��B
	CD3D11_DEFAULT defaultSettings;
	//�f�t�H���g�Z�b�e�B���O�ŏ���������B
	CD3D11_BLEND_DESC blendDesc(defaultSettings);
	//a�u�����f�B���O��L���ɂ���B
	blendDesc.RenderTarget[0].BlendEnable = true;

	//�\�[�X�J���[�̃u�����f�B���O���@���w�肵�Ă���B
	//�\�[�X�J���[�Ƃ̓s�N�Z���V�F�[�_�[����̏o�͂��w���Ă���B
	//���̎w��ł́A�\�[�X�J���[��SRC(rgba)�Ƃ���ƁA
	//�ŏI�I�ȃ\�[�X�J���[�͉��L�̂悤�Ɍv�Z�����B
	//�ŏI�I�ȃ\�[�X�J���[�@= SRC.rgb X SRC.a
	blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;

	//�f�B�X�e�B�l�[�V�����J���[�̃u�����f�B���O���@���w�肵�Ă���B
	//�f�B�X�e�B�l�[�V�����J���[�Ƃ́A
	//���łɕ`�����܂�Ă��郌���_�����O�^�[�Q�b�g�̃J���[���w���Ă���B
	//���̎w��ł́A�f�B�X�e�B�l�[�V�����J���[��DEST(rgba),
	//�\�[�X�J���[��SRC(RGBA)�Ƃ���ƁA�ŏI�I�ȃf�B�X�e�B�l�[�V�����J���[��
	//���L�̂悤�Ɍv�Z�����
	//�ŏI�I�ȃf�B�X�e�B�l�[�V�����J���[ = DEST.rgb X (1.0f - SRC.a)
	blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;

	//�ŏI�I�Ƀ����_�����O�^�[�Q�b�g�ɕ`�����܂��J���[�̌v�Z���@���w�肵�Ă���
	//���̎w�肾�ƁA1�{2�̃J���[���`�����܂��
	//�܂�A�ŏI�I�Ƀ����_�����O�^�[�Q�b�g�ɕ`�����܂��J���[��
	//SRC.rgb X SRC.a + DEST.rgb X (1.0f - SRC.a)
	//�ƂȂ�
	blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;

	//���̐ݒ�ŁA�u�����h�X�e�[�g���쐬�����
	//�������������s����u�����h�X�e�[�g���쐬�����B
	auto d3dDevice = g_graphicsEngine->GetD3DDevice();
	d3dDevice->CreateBlendState(&blendDesc, &m_translucentBlendState);
}

void Game::Update()
{
	//�v���C���[�̍X�V�B
	m_player.Update();
	for (auto& enemy : enemyList) {
		enemy->Update();
	}
	m_soundEngine.Update();
	m_camera.Update();
	m_sprite.UpdateWorldMatrix(CVector3::Zero(), CQuaternion::Identity(), CVector3::One());
}

void Game::Draw()
{

}

void Game::Render()
{
	g_graphicsEngine->BegineRender();
	auto d3dDeviceContext = g_graphicsEngine->GetD3DDeviceContext();


	CMatrix mView;
	CMatrix mProj;
	mView.MakeLookAt(
		{ 0,0,1 },
		{ 0, 0, 0 },
		{ 0,1,0 }
	);
	mProj.MakeOrthoProjectionMatrix(1280, 720, 0.1, 100);
	m_sprite.Draw(mView, mProj);
	
	float blendFactor[] = { 0.0f,0.0f,0.0f,0.0f };
	//�������������u�����h�X�e�[�g��ݒ肷��B
	d3dDeviceContext->OMSetBlendState(
		m_translucentBlendState,
		blendFactor,
		0xffffffff
	);

	////�v���C���[�̕`��B
	//m_player.Draw();
	////���x����`��
	//m_level.Draw();
	////�G�l�~�[��`��
	//for (auto& enemy : enemyList) {
	//	enemy->Draw();
	//}
}