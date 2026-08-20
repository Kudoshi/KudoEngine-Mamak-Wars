#pragma once
#include "Component.hpp"

namespace Game
{
	using namespace KudoEngine;
	class PlayerShoot : public Component
	{
	public:
		PlayerShoot(GameObject& gameObject) : Component(gameObject) {};

		void Shoot();

	private:
		float _nextShootTime = 0;
		float _shootCooldownDuration = 1.0f;

	};
}