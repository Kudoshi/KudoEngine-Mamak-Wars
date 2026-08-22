#include "RotiCanai.hpp"
#include "PlayerDie.hpp"
#include "raylib.h"
#include <string>
using namespace KudoEngine;

namespace Game
{
	void Roticanai::Awake()
	{
		_collider = GetGameObject().GetComponent<Collider>();
	}

	void Roticanai::Start()
	{
		_collider->OnCollisionEnter.Subscribe([this](Collider& other) { OnCollisionEnter(other); });
	}

	void Roticanai::Update()
	{
		Vector2 position = GetTransform().GetPosition();

		position = Vector2({ position.x + _direction.x * _moveSpeed * GetFrameTime(), position.y + _direction.y * _moveSpeed * GetFrameTime() });
		GetTransform().SetPosition(position);

		_lifetime -= GetFrameTime();

		if (_lifetime <= 0)
		{
			GetGameObject().DestroySelf();
		}
	}
	void Roticanai::OnCollisionEnter(Collider& other)
	{
		int otherID = other.GetGameObject().GetObjectID();
		int myID = GetGameObject().GetObjectID();

		if (otherID == _gameObjectIDShooter) return;
		
		PlayerDie* playerDie = other.GetGameObject().GetComponent<PlayerDie>();
		if (playerDie != nullptr)
			playerDie->Die();

		GetGameObject().DestroySelf();

		Print("Hit! " + other.GetGameObject().GetName());
	}
}