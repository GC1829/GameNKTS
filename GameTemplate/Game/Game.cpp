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

	//レベルを初期化。
	m_level.Init(L"Assets/level/School.tkl", [&](LevelObjectData& objData) {
		if (objData.EqualName(L"enemy") == true) {
			//Star。
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

	//メインレンダリングターゲットに描かれた絵を
	//フレームバッファにコピーするためのスプライトを初期化
	m_copyMainRtToFrameBufferSprite.Init(
		m_mainRenderTarget.GetRenderTargetSRV(),
		FRAME_BUFFER_W,
		FRAME_BUFFER_H
	);

	//ブレンドステートの初期化
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
	//作成するブレンドステートの情報を設定する。
	CD3D11_DEFAULT defaultSettings;
	//デフォルトセッティングで初期化する。
	CD3D11_BLEND_DESC blendDesc(defaultSettings);
	//aブレンディングを有効にする。
	blendDesc.RenderTarget[0].BlendEnable = true;

	//ソースカラーのブレンディング方法を指定している。
	//ソースカラーとはピクセルシェーダーからの出力を指している。
	//この指定では、ソースカラーをSRC(rgba)とすると、
	//最終的なソースカラーは下記のように計算される。
	//最終的なソースカラー　= SRC.rgb X SRC.a
	blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;

	//ディスティネーションカラーのブレンディング方法を指定している。
	//ディスティネーションカラーとは、
	//すでに描きこまれているレンダリングターゲットのカラーを指している。
	//この指定では、ディスティネーションカラーをDEST(rgba),
	//ソースカラーをSRC(RGBA)とすると、最終的なディスティネーションカラーは
	//下記のように計算される
	//最終的なディスティネーションカラー = DEST.rgb X (1.0f - SRC.a)
	blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;

	//最終的にレンダリングターゲットに描きこまれるカラーの計算方法を指定している
	//この指定だと、1＋2のカラーが描きこまれる
	//つまり、最終的にレンダリングターゲットに描きこまれるカラーは
	//SRC.rgb X SRC.a + DEST.rgb X (1.0f - SRC.a)
	//となる
	blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;

	//この設定で、ブレンドステートを作成すると
	//半透明合成を行えるブレンドステートが作成される。
	auto d3dDevice = g_graphicsEngine->GetD3DDevice();
	d3dDevice->CreateBlendState(&blendDesc, &m_translucentBlendState);
}

void Game::Update()
{
	//プレイヤーの更新。
	m_player.Update();
	//エネミーの更新
	for (auto& enemy : enemyList) {
		enemy->Update();
	}
	//サウンドの更新
	m_soundEngine.Update();
	//カメラの更新
	m_camera.Update();
	//画像の更新
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
	////レンダリングターゲットの切り替え
	//d3dDeviceContext->OMSetRenderTargets(1, rtTbl, depthStensil);
	//if (viewport != nullptr) {
	//	//ビューポートが指定されていたら、ビューポートも変更する。
	//	d3dDeviceContext->RSSetViewports(1, viewport);
	//}
}
void Game::Draw()
{

}
void Game::ForwordRender()
{
	////レンダリングターゲットをメインに変更する。
	//auto d3dDeviceContext = g_graphicsEngine->GetD3DDeviceContext();
	//ChangeRenderTarget(d3dDeviceContext, &m_mainRenderTarget, &m_frameBufferViewports);
	////メインレンダリングターゲットをクリアする。
	//float clearColor[] = { 0.0f,0.0f,0.0f,1.0f };
	//m_mainRenderTarget.ClearRenderTarget(clearColor);
	//
}
void Game::PostRender()
{
	////レンダリングターゲットをフレームバッファに戻す
	//auto d3dDeviceContext = g_graphicsEngine->GetD3DDeviceContext();
	//ChangeRenderTarget(
	//	d3dDeviceContext, 
	//	m_frameBufferRenderTargetView, 
	//	m_frameBufferDepthStencilView, 
	//	&m_frameBufferViewports
	//);
	////ドロドロ
	//m_copyMainRtToFrameBufferSprite.Draw();

	//m_frameBufferRenderTargetView->Release();
	//m_frameBufferDepthStencilView->Release();
}

void Game::Render()
{
	//描画開始
	g_graphicsEngine->BegineRender();
	auto d3dDeviceContext = g_graphicsEngine->GetD3DDeviceContext();
	//d3dDeviceContext->OMGetRenderTargets(
	//	1,
	//	&m_frameBufferRenderTargetView,
	//	&m_frameBufferDepthStencilView
	//);

	////ビューポートもバックアップを取っておく
	//unsigned int numViewport = 1;
	//d3dDeviceContext->RSGetViewports(&numViewport, &m_frameBufferViewports);

	////フォワードレンダリング
	//ForwordRender();

	////ポストレンダリング
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
	//半透明合成もブレンドステートを設定する。
	d3dDeviceContext->OMSetBlendState(
		m_translucentBlendState,
		blendFactor,
		0xffffffff
	);
	//プレイヤーの描画。
	m_player.Draw();
	//レベルを描画
	m_level.Draw();
	//エネミーを描画
	for (auto& enemy : enemyList) {
		enemy->Draw();
	}
	m_sprite.Draw(mView, mProj);

	//描画終了
	g_graphicsEngine->EndRender();
}