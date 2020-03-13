#include "stdafx.h"
#include <iostream>
#include "Game.h"
#include "GameObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "GameOver.h"


Game* g_game = nullptr;

Game::Game()
{
	g_game = this;
	m_soundEngine.Init();

	//m_bgm.Init(L"Assets/sound/noroinouta.wav");
	//m_bgm.Play(true);

	//���x�����������B
	m_level.Init(L"Assets/level/School.tkl", [&](LevelObjectData& objData) {
		if (objData.EqualName(L"enemy") == true) {
			//Star�B
			auto enemy = new Enemy(objData.position, objData.rotation, &m_player);
			enemyList.push_back(enemy);
			return true;
		}
		return false;
	});

	m_player.SetPosition({ -400.0f,0.0f,800.0f });
	m_camera.SetPlayer(&m_player);

	m_mainRenderTarget.Create(
		FRAME_BUFFER_W,
		FRAME_BUFFER_H,
		DXGI_FORMAT_R8G8B8A8_UNORM
	);

	//���C�������_�����O�^�[�Q�b�g�ɕ`���ꂽ�G��
	//�t���[���o�b�t�@�ɃR�s�[���邽�߂̃X�v���C�g��������
	m_copyMainRtToFrameBufferSprite.Init(
		m_mainRenderTarget.GetRenderTargetSRV(),
		FRAME_BUFFER_W,
		FRAME_BUFFER_H
	);

	//�u�����h�X�e�[�g�̏�����
	InitTranslucentBlendState();
	m_sprite.Init(L"Assets/Sprite/unity.dds", 1000, 1000);
}


Game::~Game()
{
	for (auto& enemy : enemyList) {
		delete enemy;
	}
	if (m_translucentBlendState != nullptr) {
		m_translucentBlendState->Release();
	}
}

void Game::InitTranslucentBlendState()
{
	//�쐬����u�����h�X�e�[�g�̏���ݒ肷��B
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
	blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;

	//�f�B�X�e�B�l�[�V�����J���[�̃u�����f�B���O���@���w�肵�Ă���B
	//�f�B�X�e�B�l�[�V�����J���[�Ƃ́A
	//���łɕ`�����܂�Ă��郌���_�����O�^�[�Q�b�g�̃J���[���w���Ă���B
	//���̎w��ł́A�f�B�X�e�B�l�[�V�����J���[��DEST(rgba),
	//�\�[�X�J���[��SRC(RGBA)�Ƃ���ƁA�ŏI�I�ȃf�B�X�e�B�l�[�V�����J���[��
	//���L�̂悤�Ɍv�Z�����
	//�ŏI�I�ȃf�B�X�e�B�l�[�V�����J���[ = DEST.rgb X (1.0f - SRC.a)
	blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;

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
	//�G�l�~�[�̍X�V
	for (auto& enemy : enemyList) {
		enemy->Update();
	}
	//�T�E���h�̍X�V
	m_soundEngine.Update();
	//�J�����̍X�V
	m_camera.Update();
	//�摜�̍X�V
	m_sprite.UpdateWorldMatrix(CVector3::Zero(), CQuaternion::Identity(), CVector3::One());
}


void Game::ChangeRenderTarget(ID3D11DeviceContext* d3dDeviceContext, RenderTarget* renderTarget, D3D11_VIEWPORT* viewport)
{
	//ChangeRenderTarget(
	//	d3dDeviceContext,
	//	renderTarget->GetRenderTargetView(),
	//	renderTarget->GetDepthStencilView(),
	//	viewport
	//);
}

void Game::ChangeRenderTarget(ID3D11DeviceContext* d3dDeviceContext, ID3D11RenderTargetView* renderTarget, ID3D11DepthStencilView* depthStensil, D3D11_VIEWPORT* viewport)
{
	//ID3D11RenderTargetView* rtTbl[] = {
	//	renderTarget
	//};
	////�����_�����O�^�[�Q�b�g�̐؂�ւ�
	//d3dDeviceContext->OMSetRenderTargets(1, rtTbl, depthStensil);
	//if (viewport != nullptr) {
	//	//�r���[�|�[�g���w�肳��Ă�����A�r���[�|�[�g���ύX����B
	//	d3dDeviceContext->RSSetViewports(1, viewport);
	//}
}
void Game::Draw()
{

}
void Game::ForwordRender()
{
	////�����_�����O�^�[�Q�b�g�����C���ɕύX����B
	//auto d3dDeviceContext = g_graphicsEngine->GetD3DDeviceContext();
	//ChangeRenderTarget(d3dDeviceContext, &m_mainRenderTarget, &m_frameBufferViewports);
	////���C�������_�����O�^�[�Q�b�g���N���A����B
	//float clearColor[] = { 0.0f,0.0f,0.0f,1.0f };
	//m_mainRenderTarget.ClearRenderTarget(clearColor);
	//
}
void Game::PostRender()
{
	////�����_�����O�^�[�Q�b�g���t���[���o�b�t�@�ɖ߂�
	//auto d3dDeviceContext = g_graphicsEngine->GetD3DDeviceContext();
	//ChangeRenderTarget(
	//	d3dDeviceContext, 
	//	m_frameBufferRenderTargetView, 
	//	m_frameBufferDepthStencilView, 
	//	&m_frameBufferViewports
	//);
	////�h���h��
	//m_copyMainRtToFrameBufferSprite.Draw();

	//m_frameBufferRenderTargetView->Release();
	//m_frameBufferDepthStencilView->Release();
}

void Game::Render()
{
	//�`��J�n
	g_graphicsEngine->BegineRender();
	auto d3dDeviceContext = g_graphicsEngine->GetD3DDeviceContext();
	//d3dDeviceContext->OMGetRenderTargets(
	//	1,
	//	&m_frameBufferRenderTargetView,
	//	&m_frameBufferDepthStencilView
	//);

	////�r���[�|�[�g���o�b�N�A�b�v������Ă���
	//unsigned int numViewport = 1;
	//d3dDeviceContext->RSGetViewports(&numViewport, &m_frameBufferViewports);

	////�t�H���[�h�����_�����O
	//ForwordRender();

	////�|�X�g�����_�����O
	//PostRender();

	CMatrix mView;
	CMatrix mProj;
	mView.MakeLookAt(
		{ 0,0,1 },
		{ 0, 0, 0 },
		{ 0,1,0 }
	);
	mProj.MakeOrthoProjectionMatrix(1280, 720, 0.1, 100);

	float blendFactor[] = { 0.0f,0.0f,0.0f,0.0f };
	//�������������u�����h�X�e�[�g��ݒ肷��B
	d3dDeviceContext->OMSetBlendState(
		m_translucentBlendState,
		blendFactor,
		0xffffffff
	);
	//�v���C���[�̕`��B
	m_player.Draw();
	//���x����`��
	m_level.Draw();
	//�G�l�~�[��`��
	for (auto& enemy : enemyList) {
		enemy->Draw();
	}
	m_sprite.Draw(mView, mProj);

	//�`��I��
	g_graphicsEngine->EndRender();
}