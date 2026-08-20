#include "PlayerShoot.hpp"
#include "raylib.h"
#include "RotiCanai.hpp"
using namespace KudoEngine;

namespace Game
{
	void PlayerShoot::Shoot()
	{
		float time = static_cast<float>(GetTime());
		if (time < _nextShootTime) return;

		_nextShootTime = time + _shootCooldownDuration;

		Vector2 directionShoot = GetTransform().GetForward();
		Vector2 spawnPoint = GetTransform().GetPosition() + Vector2Scale(directionShoot, 100);
		CreateRotiCanai(directionShoot, GetGameObject().GetObjectID(), spawnPoint);
	}
}