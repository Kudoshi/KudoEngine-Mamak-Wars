#include "Engine.hpp"
#include "raylib.h"

namespace KudoEngine
{
	void Engine::StartEngine()
	{
		ConfigApplication();
	}

	void Engine::ExitEngine()
	{
	}


	void Engine::ConfigApplication()
	{
		_config = EngineConfig({
			1920,
			1080,
			"Mamak Wars"
		});

		SetTargetFPS(60);

		SetupSystem();
	}
	void Engine::SetupSystem()
	{
		// Initializes manager here
		_lifecycleManager = LifecycleManager();
		_gameObjectManager = GameObjectManager();

		StartGame();
	}
	void Engine::StartGame()
	{
		_game = Game::Game();
		_game.SetupGame();
		std::cout << "[Engine] Start Game\n";
		InitWindow(_config.Width, _config.Height, _config.GameName.c_str());
		_game.SetupScene();
		_lifecycleManager.StartLifeCycleManager();
	}
}
