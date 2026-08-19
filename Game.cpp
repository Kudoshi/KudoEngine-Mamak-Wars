#include "Engine.hpp"
#include "TestObject.hpp"
using namespace KudoEngine;

namespace Game
{
	void Game::SetupGame()
	{
		Engine::Instance().GetGameObjectManager();
		GameObject& testObj = Engine::Instance().GetGameObjectManager().CreateGameObject();
		testObj.AddComponent<TestObject>();

		for (auto& component : testObj.GetComponents())
		{
			Print(typeid(*component).name());
		}
	}

}