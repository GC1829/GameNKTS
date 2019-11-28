#pragma once
#include "RenderTarget.h"

class C3DModelDraw;

class ShadowMap
{
public:
	ShadowMap();
	~ShadowMap();
	CMatrix GetLightViewMatrix() const
	{
		return m_lightViewMatrix;
	}

	CMatrix GetLightProjMatrix() const
	{
		return m_lightProjMatrix;
	}

	void UpdateFromLightDirection(CVector3 lightCameraPos, CVector3 lightDir);

	void RenderToShadowMap();

	void RegistShadowCaster(C3DModelDraw* shadowCaster)
	{
		m_shadowCasters.push_back(shadowCaster);
	}

	ID3D11ShaderResourceView* GetShadowMapSRV()
	{
		return m_shadowMapRT.GetRenderTargetSRV();
	}
private:
	CVector3 m_lightCameraPosition = CVector3::Zero();	//ライトカメラの視点
	CVector3 m_lightCameraTarget = CVector3::Zero();	//ライトカメラの注視点
	CMatrix m_lightViewMatrix = CMatrix::Identity();	//ライトビュー行列
	CMatrix m_lightProjMatrix = CMatrix::Identity();	//ライトプロジェクション行列
	RenderTarget m_shadowMapRT;							//シャドウマップを描画するレンダリングターゲット
	std::vector< C3DModelDraw*> m_shadowCasters;		//シャドウキャスターの配列

};

