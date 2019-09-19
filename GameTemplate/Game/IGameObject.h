#pragma once
class IGameObject
{
public:
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Render() = 0;
	/// <summary>
	/// �폜���N�G�X�g���s��
	/// </summary>
	void RequestDelete()
	{
		isReqDelete = true;
	}
	/// <summary>
	/// �폜���N�G�X�g���󂯂Ă���B
	/// </summary>
	/// <returns>
	/// true���A���Ă�����A���N�G�X�g���󂯂Ă���B
	/// </returns>
	bool IsRequestDelete()
	{
		return isReqDelete;
	}
private:
	bool isReqDelete = false; //�폜���N�G�X�g
};

