/*1
*@brief Transform
*/

#pragma once

namespace tyEngine {
	/*!
	*@brief Transform
	*@details
	*Unity��Transform�Ɠ��l�̎g�������ł���B
	*/
	class Transform
	{
	public:
		Transform()
		{
		}
		~Transform()
		{
		}
		/*
		*@brief  ���[���h���W���擾
		*/
		const CVector3& GetPosition() const
		{
			return m_position;
		}
		/*
		*@brief  ���[���h��]���擾
		*/
		const CQuaternion& GetRotation() const
		{
			return m_rotation;
		}
		/*
		*@brief  ���[���h�g�嗦���擾
		*/
		const CVector3& GetScale() const
		{
			return m_scale;
		}
		/*!
		 *@brief	���[�J�����W���擾�B
		 */
		const CVector3& GetLocalPosition() const
		{
			return m_localPosition;
		}
		/*!
		 *@brief	���[�J����]���擾�B
		 */
		const CQuaternion& GetLocalRotation() const
		{
			return m_localRotation;
		}
		/*!
		 *@brief	���[�J���g����擾�B
		 */
		const CVector3& GetLocalScale() const
		{
			return m_localscale;
		}
		/*!
		 *@brief	���[�J�����W��ݒ�B
		 */
		void SetLocalPosition(const CVector3& pos)
		{
			m_localPosition = pos;
		}
		/*!
		 *@brief	���[�J����]��ݒ�B
		 */
		void SetLocalRotation(const CQuaternion& rot)
		{
			m_localRotation = rot;
		}
		/*!
		 *@brief	���[�J���g�嗦��ݒ�B
		 */
		void SetLocalScale(const CVector3& scale)
		{
			m_localscale = scale;
		}
		/*!
		 *@brief	���̃C���X�^���X�Ǝq�����ׂẴ��[���h�s����X�V����B
		 */
		void UpdateWorldMatrixAll();
	private:
		Transform* m_parent = nullptr;
		std::list<Transform*> m_children;
		CVector3 m_position;
		CQuaternion m_rotation;
		CVector3 m_scale;
		CVector3 m_localPosition;
		CQuaternion m_localRotation;
		CVector3 m_localscale;
		CMatrix m_worldMatrix;
	};
}