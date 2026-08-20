#include "GameObjectManager.hpp"
#include "Engine.hpp"

namespace KudoEngine
{
	GameObjectManager& G_GameObjectManager()
	{
		return Engine::Instance().GetGameObjectManager();
	}

	GameObject& GameObjectManager::CreateGameObject()
	{
		int id = static_cast<int>(_gameObjects.size()) + 1;

		auto object = std::make_unique<GameObject>(id);

		GameObject& ref = *object;

		_gameObjects[id] = std::move(object);

		return ref;
	}

	void GameObjectManager::DestroyGameObject(GameObject& gameObject)
	{
		_gameObjects.erase(gameObject.GetObjectID());
	}




}