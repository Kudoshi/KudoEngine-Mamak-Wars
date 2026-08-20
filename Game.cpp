#include "raylib.h"
#include "Engine.hpp"
#include "Player.hpp"
using namespace KudoEngine;

namespace Game
{
	void Game::SetupGame()
	{
	}

	void Game::SetupScene()
	{
		Engine::Instance().GetGameObjectManager();

		CreatePlayer(0, { 500, 500 });
		CreatePlayer(1, { 1000, 1000 });


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