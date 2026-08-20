#include "PlayerMovement.hpp"
#include "Transform.hpp"
#include <algorithm>
#include "raymath.h"
using namespace KudoEngine;

namespace Game
{
	void PlayerMovement::Move(Vector2 movement)
	{
		_movementInput = movement;
		
		_movementInput = movement;

		if (Vector2Length(movement) > 0.0f)
		{
			movement = Vector2Normalize(movement);
		}

		_movementVelocity = Vector2Scale(movement, _movementSpeed);

	}

	void PlayerMovement::Dash()
	{
		if (_cooldown > 0) return;
		if (Vector2Length(_movementInput) == 0.0f)
			return;

		_dashVelocity = Vector2Scale(Vector2Normalize(_movementInput),_dashSpeed);
		_cooldown = _dashCooldownTime;
	}

	void PlayerMovement::Update()
	{
		float deltaTime = GetFrameTime();

		// Steer dash using current movement input
		if (Vector2Length(_dashVelocity) > 0.0f && Vector2Length(_movementInput) > 0.0f)
		{
			Vector2 dashDirection = Vector2Normalize(_movementInput);

			float dashSpeed = Vector2Length(_dashVelocity);

			_dashVelocity = Vector2Scale(dashDirection, dashSpeed);
		}

		// Decelerate dash
		float dashSpeed = Vector2Length(_dashVelocity);

		if (dashSpeed > 0.0f)
		{
			dashSpeed = std::max(0.0f, dashSpeed - _dashDeceleration * deltaTime);

			if (dashSpeed > 0.0f)
			{
				_dashVelocity = Vector2Scale(Vector2Normalize(_dashVelocity),dashSpeed);
			}
			else
			{
				_dashVelocity = { 0.0f, 0.0f };
			}
		}

		// Final velocity
		_velocity = Vector2Add(_movementVelocity,_dashVelocity);

		// Move 
		KudoEngine::Transform& transform = this->GetTransform();
		Vector2 position = transform.GetPosition();

		position = Vector2Add(position, Vector2Scale(_velocity, deltaTime));

		transform.SetPosition(position);

		// Cooldown

		_cooldown -= deltaTime;

		// Rotation

		Vector2 direction = _movementInput;

		if (Vector2Length(direction) > 0.0f)
		{
			direction = Vector2Normalize(direction);

			float angle = atan2f(direction.y, direction.x);

			float rotation = angle * RAD2DEG;

			transform.SetRotation(rotation);
		}
	}
}