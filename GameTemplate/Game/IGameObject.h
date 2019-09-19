#pragma once
class IGameObject
{
public:
	/// <summary>
	/// 更新関数
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 描画
	/// </summary>
	virtual void Render() = 0;
	/// <summary>
	/// 削除リクエストを行う
	/// </summary>
	void RequestDelete()
	{
		isReqDelete = true;
	}
	/// <summary>
	/// 削除リクエストを受けている。
	/// </summary>
	/// <returns>
	/// trueが帰ってきたら、リクエストを受けている。
	/// </returns>
	bool IsRequestDelete()
	{
		return isReqDelete;
	}
private:
	bool isReqDelete = false; //削除リクエスト
};

