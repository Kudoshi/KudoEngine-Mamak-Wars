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
		void Dash();
		void Update() override;
	private:
		float _movementSpeed = 450.0f;
		Vector2 _movementInput;
		Vector2 _movementVelocity = { 0.0f, 0.0f };
		Vector2 _dashVelocity = { 0.0f, 0.0f };
		Vector2 _velocity = { 0.0f, 0.0f };
		float _dashSpeed = 900.0f;
		float _dashDeceleration = 1500.0f;
		float _cooldown;
		float _dashCooldownTime = 2.0f;
	};
}