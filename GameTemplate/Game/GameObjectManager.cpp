#include "stdafx.h"
#include "GameObjectManager.h"

//GameObjectManager�N���X�̃C���X�^���X
GameObjectManager g_goMgr;

void GameObjectManager::Update()
{
	//�o�^����Ă���Q�[���I�u�W�F�N�g�̍X�V��������
	for (auto go : m_goList) {
		go->Update();
		go->Render();
	}
	//���ׂẴQ�[���I�u�W�F�N�g��1�t���[�����̏������I����Ă���A�폜����B
	for (auto it = m_goList.begin(); it != m_goList.end();) {
		if ((*it)->IsRequestDelete()) {
			//�폜���N�G�X�g���󂯂Ă���̂ō폜
			delete* it;
			it = m_goList.erase(it);
		}
		else {
			//���N�G�X�g���󂯂Ă��Ȃ�
			it++;
		}
	}
}