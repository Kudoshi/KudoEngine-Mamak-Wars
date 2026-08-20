#include "Collider.hpp"
#include "CollisionManager.hpp"
#include "Print.hpp"
#include "GameObject.hpp"

namespace KudoEngine
{
	bool RENDER_COLLIDER_VISUALIZATION = true;

	void Collider::CollisionDetected(Collider& other)
	{
		Print("Detected! Colliding with " + other.GetGameObject().GetName());
		OnCollisionEnter.Invoke(other);
	}
	void KudoEngine::Collider::Start()
	{
		Vector2 position = GetTransform().GetPosition();
		_colliderRect = Rectangle({ position.x, position.y, _width, _height });
		CollisionManager::Instance().RegisterCollider(*this);
	}
	void Collider::Update()
	{
		Vector2 position = GetTransform().GetPosition();

		_colliderRect.x = position.x;
		_colliderRect.y = position.y;
	}
	void Collider::Destroy()
	{
		CollisionManager::Instance().UnregisterCollider(*this);

	}
	void Collider::Render()
	{
		if (!RENDER_COLLIDER_VISUALIZATION) return;

		Vector2 position = GetTransform().GetPosition();

		Vector2 origin = {_colliderRect.width / 2.0f,_colliderRect.height / 2.0f};

		DrawRectanglePro(_colliderRect, origin, 0, Color({ 230, 41, 55, 100 }));
	}
}

