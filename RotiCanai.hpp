#pragma once
#include "raylib.h"
#include "Engine.hpp"
#include "TestObject.hpp"
#include "SpriteRenderer.hpp"
#include "PlayerInput.hpp"
#include "Transform.hpp"
#include "Collider.hpp"

namespace Game
{
	using namespace KudoEngine;

	class Roticanai : public Component
	{
	public:
		Roticanai(GameObject& gameObject, int gameObjectIDShooter, Vector2 direction) : 
			Component(gameObject), _gameObjectIDShooter(gameObjectIDShooter), _direction(direction) {};
	
	private:
		int _gameObjectIDShooter;
		Vector2 _direction;
		float _moveSpeed = 1200;
		//float _moveSpeed = 0;
		float _lifetime = 4;
		Collider* _collider;
		int _colliderEventID;
		void Awake() override;
		void Start() override;
		void Update() override;
		void OnCollisionEnter(Collider& other);
	};

	inline Roticanai& CreateRotiCanai(Vector2 direction, int gameObjectIDShooter, Vector2 spawnPoint)
	{
		GameObject& roticanai = Engine::Instance().GetGameObjectManager().CreateGameObject("RotiCanai by Player " + std::to_string(gameObjectIDShooter));
		roticanai.GetTransform().SetPosition(spawnPoint);
		roticanai.GetTransform().SetScale({ 0.5f, 0.5f });
		
		SpriteRenderer& renderer = roticanai.AddComponent<SpriteRenderer>();
		renderer.SetShape(Shape2D::Circle, RED);
		//renderer.SetSprite(LoadTexture("Resources/Roticanai.png"));
		Roticanai& logic = roticanai.AddComponent<Roticanai>(gameObjectIDShooter, direction);
		roticanai.AddComponent<Collider>(50, 50);
		return logic;
	}
}