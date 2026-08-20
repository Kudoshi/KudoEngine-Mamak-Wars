#include "PlayerDie.hpp"
using namespace KudoEngine;

namespace Game {
	void PlayerDie::Die()
	{
		// Doing this way because if i deactivated the gameobject, the timer would not run anymore

		GetTransform().SetPosition({ 9999,9999 });
		_isDead = true;
		_currentRespawnTime = _respawnTime;
		_deadCount++;
	}

	void PlayerDie::Update()
	{
		if (!_isDead) return;

		_currentRespawnTime -= GetFrameTime();

		if (_currentRespawnTime <= 0)
		{
			Vector2 point = { (float)GetRandomValue(0, GetScreenWidth()), (float)GetRandomValue(0, GetScreenHeight()) };
			GetTransform().SetPosition(point);
			_isDead = false;
		}
	}

	void PlayerDie::Render()
	{
		int playerIdx = _playerIdx == 0 ? 2 : 1;
		std::string text = "Player " + std::to_string(playerIdx) + " kills: " + std::to_string(_deadCount);
		int fontSize = 45;
		int padding = 20;

		int x;
		Color color;

		if (_playerIdx == 0)
		{
			x = GetScreenWidth() - MeasureText(text.c_str(), fontSize) - padding;
			color = GREEN;
		}
		else
		{
			x = padding;
			color = BLUE;

		}
			
		int y = 30;
		DrawText(text.c_str(), x, y, fontSize, color);

	}

}
