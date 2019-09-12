#pragma once
class BackGround
{
public:
	BackGround();
	~BackGround();
	void Update();
	void Draw();
private:
	SkinModel m_model;
	PhysicsWorld g_physics;
};