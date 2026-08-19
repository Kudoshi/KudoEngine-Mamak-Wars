#pragma once
#include "Component.hpp"

namespace Game
{
	using GameObject = KudoEngine::GameObject;

	class PlayerInput : public KudoEngine::Component
	{
	public:
		PlayerInput(GameObject& gameObject, int gamepadIdx) : Component(gameObject), _gamepadIdx(gamepadIdx) {}

		void Update() override;

	private:
		int _gamepadIdx;
	};
}