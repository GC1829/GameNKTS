/*1
*@brief Transform
*/

#pragma once

namespace tyEngine {
	/*!
	*@brief Transform
	*@details
	*UnityのTransformと同様の使い方ができる。
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
		*@brief  ワールド座標を取得
		*/
		const CVector3& GetPosition() const
		{
			return m_position;
		}
		/*
		*@brief  ワールド回転を取得
		*/
		const CQuaternion& GetRotation() const
		{
			return m_rotation;
		}
		/*
		*@brief  ワールド拡大率を取得
		*/
		const CVector3& GetScale() const
		{
			return m_scale;
		}
		/*!
		 *@brief	ローカル座標を取得。
		 */
		const CVector3& GetLocalPosition() const
		{
			return m_localPosition;
		}
		/*!
		 *@brief	ローカル回転を取得。
		 */
		const CQuaternion& GetLocalRotation() const
		{
			return m_localRotation;
		}
		/*!
		 *@brief	ローカル拡大を取得。
		 */
		const CVector3& GetLocalScale() const
		{
			return m_localscale;
		}
		/*!
		 *@brief	ローカル座標を設定。
		 */
		void SetLocalPosition(const CVector3& pos)
		{
			m_localPosition = pos;
		}
		/*!
		 *@brief	ローカル回転を設定。
		 */
		void SetLocalRotation(const CQuaternion& rot)
		{
			m_localRotation = rot;
		}
		/*!
		 *@brief	ローカル拡大率を設定。
		 */
		void SetLocalScale(const CVector3& scale)
		{
			m_localscale = scale;
		}
		/*!
		 *@brief	このインスタンスと子供すべてのワールド行列を更新する。
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