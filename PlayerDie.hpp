#pragma once
#include "Component.hpp"
#include "GameObject.hpp"

namespace Game
{
	using namespace KudoEngine;

	class PlayerDie : public Component
	{
	public:
		PlayerDie(GameObject& gameObject, int playerIdx) : Component(gameObject), _playerIdx(playerIdx) {};

		void Die();
		
	private:
		float _currentRespawnTime;
		bool _isDead = false;
		float _respawnTime = 3.0f;
		int _deadCount;
		int _playerIdx;

		void Update() override;
		void Render() override;
	};
}