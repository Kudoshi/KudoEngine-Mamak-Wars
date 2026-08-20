#pragma once
#include "Component.hpp"
#include "raylib.h"
#include "raymath.h"
namespace KudoEngine
{
	class GameObject;

	class Transform : public Component
	{
	public:
		Transform(GameObject& gameObject) : Component(gameObject), _position({ 0, 0 }), _rotation(0), _scale({ 1, 1 }) {
			InternalSetTransform(*this);
		};
		void SetPosition(Vector2 position) { _position = position; };
		void SetRotation(float rotation) { _rotation = rotation; };
		void SetScale(Vector2 scale) { _scale = scale; };

		Vector2 GetPosition() const { return _position; }
		float GetRotation() const { return _rotation; }
		const Vector2 GetScale() const { return _scale; }
		Vector2 GetForward() const { return Vector2Rotate({ 1, 0 }, _rotation * DEG2RAD); };
		

	private:
		Vector2 _position;
		float _rotation;
		Vector2 _scale;
	};
}