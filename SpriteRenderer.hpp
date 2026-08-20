#pragma once
#include "Component.hpp"
#include "Shape2D.hpp"
#include "raylib.h"

namespace KudoEngine
{
	class Transform;

	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer(GameObject& gameObject) : Component(gameObject), _spriteColor(WHITE) {}

		void SetShape(Shape2D shape, Color spriteColor = WHITE) { _shapeSprite = shape; _spriteColor = spriteColor; };
		void SetSprite(Texture2D texture) {
			_shapeSprite = Shape2D::Sprite;
			_texture2D = texture;
		}
		void SetColor(Color color) { _spriteColor = color; };

		void Render() override;
	private:
		Shape2D _shapeSprite;
		Texture2D _texture2D;
		Color _spriteColor;
	};
}