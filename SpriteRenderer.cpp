#include "Transform.hpp"
#include "SpriteRenderer.hpp"
#include "raylib.h"
#include "raymath.h"

namespace KudoEngine
{

	void SpriteRenderer::Render() 
	{
		Vector2 position = GetTransform().GetPosition();
		Vector2 scale = GetTransform().GetScale(); // We doing 1 unit = 100
		float rotation = GetTransform().GetRotation();

		if (_shapeSprite == Shape2D::Sprite && _texture2D.id != 0)
		{
			float width = _texture2D.width * scale.x;
			float height = _texture2D.height * scale.y;
			Rectangle rectSrc = { 0, 0, (float) _texture2D.width, (float)_texture2D.height };
			Rectangle rectDestination = { position.x, position.y, width, height };
			Vector2 origin = { width / 2.0f, height / 2.0f };

			DrawTexturePro(_texture2D, rectSrc, rectDestination, origin, rotation, _spriteColor);

		}
		else if (_shapeSprite == Shape2D::Circle)
		{
			scale *= 100;
			float radius = scale.x / 2.0f;
			DrawCircle(position.x, position.y, radius, _spriteColor);
		}
		else if (_shapeSprite == Shape2D::Rectangle)
		{
			scale *= 100;
			Rectangle rect = { position.x, position.y, scale.x, scale.y };
			DrawRectanglePro(rect, { scale.x / 2.0f, scale.y / 2.0f }, rotation, _spriteColor);
		}
		else if (_shapeSprite == Shape2D::Triangle)
		{
			scale *= 100;
			float halfWidth = scale.x / 2.0f;
			float halfHeight = scale.y / 2.0f;

			Vector2 points[] =
			{
				{ 0, -halfHeight },
				{ -halfWidth, halfHeight },
				{ halfWidth, halfHeight }
			};

			for (Vector2& point : points)
			{
				point = Vector2Rotate(point, rotation * DEG2RAD);
				point.x += position.x;
				point.y += position.y;
			}

			DrawTriangle(points[0], points[1], points[2], RED);
		}
	}


}