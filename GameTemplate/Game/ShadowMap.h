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
	CVector3 m_lightCameraPosition = CVector3::Zero();	//���C�g�J�����̎��_
	CVector3 m_lightCameraTarget = CVector3::Zero();	//���C�g�J�����̒����_
	CMatrix m_lightViewMatrix = CMatrix::Identity();	//���C�g�r���[�s��
	CMatrix m_lightProjMatrix = CMatrix::Identity();	//���C�g�v���W�F�N�V�����s��
	RenderTarget m_shadowMapRT;							//�V���h�E�}�b�v��`�悷�郌���_�����O�^�[�Q�b�g
	std::vector< C3DModelDraw*> m_shadowCasters;		//�V���h�E�L���X�^�[�̔z��

};

