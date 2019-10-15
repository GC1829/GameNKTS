#pragma once
class RenderTarget
{
public:
	RenderTarget();
	~RenderTarget();
	void Release();
	void Create(unsigned int w, unsigned int h, DXGI_FORMAT texFormat);
	void ClearRenderTarget(float* clearColor);
	ID3D11RenderTargetView* GetRenderTargetView()
	{

	}
	ID3D11DepthStencilView* GetDepthStencilView()
	{

	}
	ID3D11ShaderResourceView* GetRenderTargetSRV()
	{


	}
private:
	ID3D11Texture2D* m_renderTargetTex = nullptr;
	ID3D11RenderTargetView* m_renderTargetView = nullptr;
	ID3D11ShaderResourceView* m_renderTargetSRV = nullptr;
	ID3D11Texture2D* m_depthStencilTex = nullptr;
	ID3D11DepthStencilView* m_depthStencilView = nullptr;
};

