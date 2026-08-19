#pragma once
#include "Component.hpp"
#include "PlayerMovement.hpp"
#include "GameObject.hpp"

namespace Game
{
	using GameObject = KudoEngine::GameObject;

	class PlayerInput : public KudoEngine::Component
	{
	public:
		PlayerInput(GameObject& gameObject, int gamepadIdx) : Component(gameObject), _gamepadIdx(gamepadIdx) {}

		void Awake() override;
		void Update() override;

	private:
		int _gamepadIdx;
		PlayerMovement* _playerMovement;
	};
}