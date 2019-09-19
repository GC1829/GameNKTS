#pragma once

#include <vector>
#include "IGameObject.h"
class GameObjectManager
{
public:
	/// <summary>
	/// �X�V
	/// </summary>
	void Update();
	/// <summary>
	/// �Q�[���I�u�W�F�N�g��ǉ�
	/// </summary>
	template <class T>
	T* NewGO()
	{
		T* newObj = new T;
		m_goList.push_back(newObj);
		return newObj;
	}
	/// <summary>
	/// �Q�[���I�u�W�F�N�g�����X�g����A�폜����B
	/// </summary>
	/// <param name="go">�폜����Q�[���I�u�W�F�N�g</param>
	void DeleteGO(IGameObject* go)
	{
		//���X�g���猟�����āA����������폜����B
		for (auto it = m_goList.begin();
			it != m_goList.end();
			it++
			) {
			if ((*it) == go) {
				//�폜���N�G�X�g�𑗂�
				go->RequestDelete();
				return;
			}
		}
	}
private:
	std::vector< IGameObject* > m_goList;
};

//�O������A�N�Z�X����̂ŁAextern�錾���K�v
extern GameObjectManager g_goMgr;

