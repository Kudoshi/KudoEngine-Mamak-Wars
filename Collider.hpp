#pragma once
#include "Component.hpp"
#include "raylib.h"

namespace KudoEngine
{

	class Collider : public Component
	{
	public:
		Collider(GameObject& gameObject, Rectangle rect) : Component(gameObject), _colliderRect(rect) {};

	private:
		Rectangle _colliderRect;

	protected:
		void Update() override;
	};
}