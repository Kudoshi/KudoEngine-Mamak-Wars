#include "Engine.hpp"
#include "TestObject.hpp"
#include "SpriteRenderer.hpp"
#include "PlayerInput.hpp"
using namespace KudoEngine;

namespace Game
{
	void Game::SetupGame()
	{
	}

	void Game::SetupScene()
	{
		Engine::Instance().GetGameObjectManager();

		// First player
		GameObject& testObj = Engine::Instance().GetGameObjectManager().CreateGameObject();
		testObj.AddComponent<TestObject>();

		SpriteRenderer& spriteRenderer = testObj.AddComponent<SpriteRenderer>();
		//spriteRenderer.SetShape(Shape2D::Circle, BLUE);
		spriteRenderer.SetSprite(LoadTexture("Resources/character_ring_indicator.png"));

		testObj.GetTransform().SetPosition({ 500, 500 });
		testObj.GetTransform().SetScale({ 0.5f, 0.5f });
		testObj.AddComponent<PlayerInput>(0);
		testObj.AddComponent<PlayerMovement>();


		// Second Player

		/*GameObject& testObj2 = Engine::Instance().GetGameObjectManager().CreateGameObject();
		testObj2.AddComponent<TestObject>();

		SpriteRenderer& spriteRenderer2 = testObj2.AddComponent<SpriteRenderer>();
		spriteRenderer2.SetShape(Shape2D::Circle, BLUE);

		testObj2.GetTransform().SetPosition({ 500, 500 });

		testObj2.AddComponent<PlayerInput>(1);
		testObj2.AddComponent<PlayerMovement>();*/
	}
}