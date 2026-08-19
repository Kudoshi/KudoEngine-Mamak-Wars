#include "PlayerInput.hpp"
#include "raylib.h"
#include "Print.hpp"
using namespace KudoEngine;

namespace Game
{
	// Set axis deadzones
	const float leftStickDeadzoneX = 0.1f;
	const float leftStickDeadzoneY = 0.1f;

	void PlayerInput::Awake()
	{
		_playerMovement = GetGameObject().GetComponent<PlayerMovement>();
	}

	void PlayerInput::Update()
	{

		if (IsGamepadAvailable(_gamepadIdx))
		{
			// -- Get left stick

			// Get axis values
			float leftStickX = GetGamepadAxisMovement(_gamepadIdx, GAMEPAD_AXIS_LEFT_X);
			float leftStickY = GetGamepadAxisMovement(_gamepadIdx, GAMEPAD_AXIS_LEFT_Y);

			// Calculate deadzones
			if (leftStickX > -leftStickDeadzoneX && leftStickX < leftStickDeadzoneX) leftStickX = 0.0f;
			if (leftStickY > -leftStickDeadzoneY && leftStickY < leftStickDeadzoneY) leftStickY = 0.0f;

			_playerMovement->Move(Vector2({ leftStickX, leftStickY }));

			// -- Buttons

			// Dash
			if (IsGamepadButtonPressed(_gamepadIdx, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
			{
				Print("[DEBUG] Dash pressed");
			}

			// Shoot
			if (IsGamepadButtonPressed(_gamepadIdx, GAMEPAD_BUTTON_RIGHT_FACE_LEFT))
			{
				Print("[DEBUG] Shoot pressed");

			}

		}
	}

}