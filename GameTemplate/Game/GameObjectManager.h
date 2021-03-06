#pragma once

#include <vector>
#include "IGameObject.h"
class GameObjectManager
{
public:
	/// <summary>
	/// 更新
	/// </summary>
	void Update();
	/// <summary>
	/// ゲームオブジェクトを追加
	/// </summary>
	template <class T>
	T* NewGO()
	{
		T* newObj = new T;
		m_goList.push_back(newObj);
		return newObj;
	}
	/// <summary>
	/// ゲームオブジェクトをリストから、削除する。
	/// </summary>
	/// <param name="go">削除するゲームオブジェクト</param>
	void DeleteGO(IGameObject* go)
	{
		//リストから検索して、見つかったら削除する。
		for (auto it = m_goList.begin();
			it != m_goList.end();
			it++
			) {
			if ((*it) == go) {
				//削除リクエストを送る
				go->RequestDelete();
				return;
			}
		}
	}
private:
	std::vector< IGameObject* > m_goList;
};

//外部からアクセスするので、extern宣言も必要
extern GameObjectManager g_goMgr;

