#pragma once
#include "raylib.h"
#include "Engine.hpp"
#include "TestObject.hpp"
#include "SpriteRenderer.hpp"
#include "PlayerInput.hpp"
#include "Collider.hpp"
using namespace KudoEngine;

namespace Game
{
	void inline CreatePlayer(int playerIdx, Vector2 spawnPosition)
	{
		// First player
		GameObject& testObj = Engine::Instance().GetGameObjectManager().CreateGameObject("Player " + std::to_string(playerIdx));
		testObj.AddComponent<TestObject>();

		SpriteRenderer& spriteRenderer = testObj.AddComponent<SpriteRenderer>();
		//spriteRenderer.SetShape(Shape2D::Circle, BLUE);
		spriteRenderer.SetSprite(LoadTexture("Resources/character_ring_indicator.png"));

		testObj.GetTransform().SetPosition(spawnPosition);
		testObj.GetTransform().SetScale({ 0.5f, 0.5f });
		testObj.AddComponent<PlayerInput>(playerIdx);
		testObj.AddComponent<PlayerMovement>();
		testObj.AddComponent<Collider>(100, 100);
	}
}