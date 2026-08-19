#pragma once
#include "Component.hpp"
#include "raylib.h"
using namespace KudoEngine;

namespace Game
{
	class PlayerMovement : public Component
	{
	public:
		PlayerMovement(GameObject& gameObject) : Component(gameObject) {};
		void Move(Vector2 movement);

	private:
		float _movementSpeed = 300.0f;
	};
}