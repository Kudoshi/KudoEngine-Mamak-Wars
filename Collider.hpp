#pragma once
#include "Component.hpp"
#include "raylib.h"
#include "Event.hpp"

namespace KudoEngine
{

	class Collider : public Component
	{
	public:
		Collider(GameObject& gameObject, float width, float height) : Component(gameObject), _width(width), _height(height) {};

		void CollisionDetected(Collider& other);

		Rectangle GetColliderRect() { return _colliderRect; };
		Event<Collider&> OnCollisionEnter;

	private:
		Rectangle _colliderRect;
		float _width;
		float _height;

	protected:
		void Start() override;
		void Update() override;
		void Destroy() override;
		void Render() override;
	};
}