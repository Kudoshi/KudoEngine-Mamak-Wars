#include "GameObjectManager.hpp"

namespace KudoEngine
{
	GameObject& GameObjectManager::CreateGameObject()
	{
		auto object = std::make_unique<GameObject>();

		int id = static_cast<int>(_gameObjects.size()) + 1;

		GameObject& ref = *object;

		_gameObjects[id] = std::move(object);

		return ref;
	}

}