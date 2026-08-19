#include "PlayerMovement.hpp"
#include "Transform.hpp"

using namespace KudoEngine;

namespace Game
{
	void PlayerMovement::Move(Vector2 movement)
	{
		KudoEngine::Transform& transform = this->GetTransform();

		Vector2 position = transform.GetPosition();
		Vector2 newPosition({ position.x + movement.x * _movementSpeed * GetFrameTime(), position.y + movement.y * _movementSpeed * GetFrameTime() });

		transform.SetPosition(newPosition);
	}
}