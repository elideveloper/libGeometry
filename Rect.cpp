#include "Rect.h"

Rect::Rect() : position(Vec2D()), direction(Vec2D()), halfWidth(0.0), halfHeight(0.0)
{
}

Rect::Rect(const Rect& rect)
	: position(rect.position), direction(rect.direction), halfWidth(rect.halfWidth), halfHeight(rect.halfHeight)
{

}

Rect::Rect(const Vec2D& pos, const Vec2D& dir, double hWidth, double hHeight)
	: position(pos), direction(dir), halfWidth(hWidth), halfHeight(hHeight)
{

}