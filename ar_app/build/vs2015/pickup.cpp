#include "pickup.h"

namespace hovar
{
	Pickup::Pickup()
	{
		collected_ = false;
		energy_ = 20.0f;
	}


	Pickup::~Pickup()
	{
	}

	void Pickup::Update(float dt)
	{
		GameObject::Update();
		// rotate
		GetLocalTransform()->Rotate(gef::Vector4(0.0f, 0.0f, dt * 45.0f));
	}

	void Pickup::Render(gef::Renderer3D * renderer)
	{
		renderer->DrawMesh(*this);
		//renderer->DrawMesh(*collider_);
	}
}