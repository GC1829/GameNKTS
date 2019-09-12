#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

namespace tyEngine {
	class GameObject;
	class RenderContext;
	typedef unsigned char  GameObjectPrio;
	/*!
	*@brief ゲームオブジェクト
	*/
	class TGameObject : Noncopyable {
	public:
		using TGameObjectIsBase = TGameObject;
	};
}
class GameObject
{
public:
	GameObject();
	~GameObject();
};
#endif // !_GAMEOBJECT_H_

