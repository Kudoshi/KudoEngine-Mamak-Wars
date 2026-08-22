#pragma once
#include "raylib.h"
#include "GameObject.hpp"
#include "Engine.hpp"
#include "Collider.hpp"
#include "SpriteRenderer.hpp"

namespace Game
{
	using namespace KudoEngine;

	void inline GenerateObstacle(int obstacleCount, float obstacleMinSize, float obstacleMaxSize)
	{
		for (int i = 0; i < obstacleCount; i++)
		{
			float x = (float)GetRandomValue(0, GetScreenWidth());
			float y = (float)GetRandomValue(0, GetScreenHeight());

			float scale = (float)GetRandomValue(obstacleMinSize, obstacleMaxSize) / 100;

			GameObject& obstacle = Engine::Instance().GetGameObjectManager().CreateGameObject("Obstacle " + std::to_string(i));
			obstacle.GetTransform().SetPosition({ x,y });
			obstacle.GetTransform().SetScale({ scale, scale });

			SpriteRenderer& spriteRenderer = obstacle.AddComponent<SpriteRenderer>();
			spriteRenderer.SetShape(Shape2D::Rectangle, GRAY);
			obstacle.AddComponent<Collider>(scale*100, scale*100);
		}
	}
}