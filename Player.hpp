#pragma once
#include "raylib.h"
#include "Engine.hpp"
#include "TestObject.hpp"
#include "SpriteRenderer.hpp"
#include "PlayerInput.hpp"
#include "Collider.hpp"
#include "PlayerShoot.hpp"
#include "PlayerDie.hpp"
namespace Game
{
	using namespace KudoEngine;

	void inline CreatePlayer(int playerIdx, Vector2 spawnPosition, Color playerColor)
	{
		// First player
		GameObject& playerObj = Engine::Instance().GetGameObjectManager().CreateGameObject("Player " + std::to_string(playerIdx));
		playerObj.AddComponent<TestObject>();

		SpriteRenderer& spriteRenderer = playerObj.AddComponent<SpriteRenderer>();
		//spriteRenderer.SetShape(Shape2D::Circle, BLUE);
		spriteRenderer.SetSprite(LoadTexture("Resources/character_ring_indicator.png"));
		spriteRenderer.SetColor(playerColor);

		playerObj.GetTransform().SetPosition(spawnPosition);
		playerObj.GetTransform().SetScale({ 0.3f, 0.3f });
		playerObj.AddComponent<PlayerInput>(playerIdx);
		playerObj.AddComponent<PlayerMovement>();
		playerObj.AddComponent<Collider>(100, 100);
		playerObj.AddComponent<PlayerShoot>();
		playerObj.AddComponent<PlayerDie>(playerIdx);
	}
}