#pragma once
#include "GameObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "level/Level.h"
#include "SoundEngin.h"
#include "SoundSouce.h"
#include "Sprite.h"
#include "RenderTarget.h"

class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	void Draw();
	void Render();
	std::vector<Enemy*>& GetEnemyList()
	{
		return enemyList;
	}
private:
	/// <summary>
	/// �t�H���[�h�����_�����O
	/// </summary>
	void ForwordRender();
	/// <summary>
	/// �����������̃u�����h�X�e�[�g��������
	/// </summary>
	void InitTranslucentBlendState();
	/// <summary>
	/// �|�X�g�����_�����O
	/// </summary>
	void PostRender();
	/// <summary>
	/// �����_�����O�^�[�Q�b�g�̐؂�ւ�
	/// </summary>
	void ChangeRenderTarget(ID3D11DeviceContext* d3dDeviceContext,RenderTarget* renderTarget,D3D11_VIEWPORT* viewport);
	void ChangeRenderTarget(ID3D11DeviceContext* d3dDeviceContext, ID3D11RenderTargetView* renderTarget, ID3D11DepthStencilView* depthstensil, D3D11_VIEWPORT* viewport);
private:
	RenderTarget m_mainRenderTarget;
	SoundEngine m_soundEngine;
	Player m_player;
	Sprite m_sprite;
	GameCamera m_camera;
	Level m_level;
	BackGround m_ground;
	std::vector<Enemy*> enemyList;
	SoundSource m_bgm;

	Sprite m_copyMainRtToFrameBufferSprite;
	D3D11_VIEWPORT m_frameBufferViewports;
	ID3D11BlendState* m_translucentBlendState = nullptr;
	ID3D11RenderTargetView* m_frameBufferRenderTargetView = nullptr;
	ID3D11DepthStencilView* m_frameBufferDepthStencilView = nullptr;

};
extern Game* g_game;
