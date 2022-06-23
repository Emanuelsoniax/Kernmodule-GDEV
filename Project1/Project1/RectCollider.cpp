#include "RectCollider.h"

RectCollider::RectCollider(Vector2D _position, Vector2D _size)
{
	top = _position.y;
	left = _position.x;
	height = _size.y;
	width = _size.x;
}

RectCollider::RectCollider(float _left, float _top, float _width, float _height)
{
	left = _left;
	top = _top;
	height = _height;
	width = _width;
}

bool RectCollider::Intersection(RectCollider target)
{
	//corners of collider
	float topEdgeCollider = top;
	float rightEdgeCollider = left + width;
	float bottomEdgeCollider = top + height;
	float leftEdgeCollider = left;

	//corners of target
	float topEdgeTarget = target.top;
	float rightEdgeTarget = target.left + target.width;
	float bottomEdgeTarget = target.top + target.height;
	float leftEdgeTarget = target.left;

	if (leftEdgeCollider < rightEdgeTarget &&
		rightEdgeCollider > leftEdgeTarget &&
		bottomEdgeCollider > topEdgeTarget &&
		topEdgeCollider < bottomEdgeTarget) {

		return true;
	}

	return false;
}
