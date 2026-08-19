#include "Engine.hpp"
#include "TestObject.hpp"
#include "SpriteRenderer.hpp"
#include "PlayerInput.hpp"
using namespace KudoEngine;

namespace Game
{
	void Game::SetupGame()
	{
		SetupScene();
	}

	void Game::SetupScene()
	{
		Engine::Instance().GetGameObjectManager();
		GameObject& testObj = Engine::Instance().GetGameObjectManager().CreateGameObject();
		testObj.AddComponent<TestObject>();

		for (auto& component : testObj.GetComponents())
		{
			Print(typeid(*component).name());
		}

		SpriteRenderer& spriteRenderer = testObj.AddComponent<SpriteRenderer>();
		spriteRenderer.SetShape(Shape2D::Circle, BLUE);

		testObj.GetTransform().SetPosition({ 100, 100 });

		testObj.AddComponent<PlayerInput>(0);
	}
}