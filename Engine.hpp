#pragma once

#include <iostream>
#include <string>
#include "LifecycleManager.hpp"
#include "GameObjectManager.hpp"
#include "GameObject.hpp"
#include "Game.hpp"
#include <memory>
#include "Behaviour.hpp"
#include <vector>

using namespace std;

namespace KudoEngine
{
	struct EngineConfig
	{
		int Width;
		int Height;	
		string GameName;
	};


	// Start Application -> Config Application -> Setup System -> Start Game
	// In Start Game you call Application Setup Game which initializes the Application Side
	class Engine {
		
		public:
			static Engine& Instance()
			{
				static Engine engine;
				return engine;
			}

			void StartEngine();
			void ExitEngine();

			Engine(const Engine&) = delete;
			Engine& operator=(const Engine&) = delete;
		// Getters
		public:
			LifecycleManager& GetLifecycleManager()
			{
				return _lifecycleManager;
			}

			GameObjectManager& GetGameObjectManager()
			{
				return _gameObjectManager;
			}

		private: 
			void ConfigApplication();
			void SetupSystem();
			void StartGame();
			EngineConfig _config;
			LifecycleManager _lifecycleManager;
			GameObjectManager _gameObjectManager;
			Game::Game _game;
			Engine() = default;

	};



}

