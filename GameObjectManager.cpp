#include "GameObjectManager.hpp"
#include "Engine.hpp"

namespace KudoEngine
{
	GameObjectManager& G_GameObjectManager()
	{
		return Engine::Instance().GetGameObjectManager();
	}

	GameObject& GameObjectManager::CreateGameObject(std::string objectName)
	{
		_gameObjectTotalSpawned++;

		auto object = std::make_unique<GameObject>(_gameObjectTotalSpawned, objectName);

		GameObject& ref = *object;

		_gameObjects[_gameObjectTotalSpawned] = std::move(object);

		return ref;
	}

	void GameObjectManager::DestroyGameObject(GameObject& gameObject)
	{
 		_gameObjects.erase(gameObject.GetObjectID());
	}




}