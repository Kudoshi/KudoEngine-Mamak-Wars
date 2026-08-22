#include "CollisionManager.hpp"
#include "GameObject.hpp"

namespace KudoEngine
{
	void CollisionManager::ResetCollisionManager()
	{

	}
	void CollisionManager::InternalPhysicsLoop()
	{
		for (size_t i = 0; i < _colliders.size(); ++i)
		{
			Collider* a = _colliders[i];

			if (!a->GetGameObject().IsActive()) continue;

			for (size_t j = i + 1; j < _colliders.size(); ++j)
			{
				Collider* b = _colliders[j];

				if (!b->GetGameObject().IsActive()) continue;
				
				if (CheckCollisionRecs(a->GetColliderRect(), b->GetColliderRect()))
				{
					a->CollisionDetected(*b);
					b->CollisionDetected(*a);
				}
			}
		}

	}
	void CollisionManager::RegisterCollider(Collider& collider)
	{
		_colliders.push_back(&collider);
	}
	void CollisionManager::UnregisterCollider(Collider& collider)
 	{
		for (auto it = _colliders.begin(); it != _colliders.end(); ++it)
		{
			if (*it == &collider)
			{
				_colliders.erase(it);
				return;
			}
		}
	}
}