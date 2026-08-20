#pragma once
#include <vector>
#include "Collider.hpp"

namespace KudoEngine
{
	class CollisionManager
	{
	public: 
		static CollisionManager& Instance()
		{
			static CollisionManager instance;
			return instance;
		}

		CollisionManager(const CollisionManager&) = delete;
		CollisionManager& operator =(const CollisionManager&) = delete;

	public:
		void ResetCollisionManager();
		void InternalPhysicsLoop();
		void RegisterCollider(Collider& collider);
		void UnregisterCollider(Collider& collider);

	private:
		CollisionManager() = default;

		std::vector<Collider*> _colliders;
	};
}