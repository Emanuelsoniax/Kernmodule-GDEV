#pragma once
#include "Vector2D.h"
class RectCollider
{
	public:
	float top;
	float left;
	float height;
	float width;
	RectCollider(Vector2D _position, Vector2D _size);
	RectCollider(float _left, float _top, float _width, float _height);
	bool Intersection(RectCollider target);

};

