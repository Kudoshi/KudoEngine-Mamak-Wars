#pragma once
#include "Component.hpp"
#include "raylib.h"

namespace KudoEngine
{
	class Transform : public Component
	{
	public:
		Transform() : _position{ 0, 0 }, _rotation{ 0, 0 }, _scale{ 1, 1 } {};
		void SetPosition(Vector2 position) { _position = position; };
		void SetRotation(Vector2 rotation) { _rotation = rotation; };
		void SetScale(Vector2 scale) { _scale = scale; };

		const Vector2& GetPosition() const { return _position; }
		const Vector2& GetRotation() const { return _rotation; }
		const Vector2& GetScale() const { return _scale; }

	private:
		Vector2 _position;
		Vector2 _rotation;
		Vector2 _scale;
	};
}