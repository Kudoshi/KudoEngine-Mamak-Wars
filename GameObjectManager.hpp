#pragma once

#include <map>
#include <memory>
#include "GameObject.hpp"
#include <string>

namespace KudoEngine
{
	class Engine;

	class GameObjectManager
	{

	public:
		GameObject& CreateGameObject(std::string objectName);
		void DestroyGameObject(GameObject& gameObject);
	public:
		std::map<int, std::unique_ptr<GameObject>>* GetGameObjects() {
			if (_gameObjects.size() == 0) return nullptr;

			return &_gameObjects;
		};
	private:
		std::map<int, std::unique_ptr<GameObject>> _gameObjects;
	};

	GameObjectManager& G_GameObjectManager();
}