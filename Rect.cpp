#include "Rect.h"

Rect::Rect() : Shape(), halfWidth(0.0), halfHeight(0.0)
{}

Rect::Rect(const Rect& rect)
	: Shape(rect.position, rect.direction), halfWidth(rect.halfWidth), halfHeight(rect.halfHeight)
{}

Rect::Rect(const Vec2D& pos, const Vec2D& dir, double hWidth, double hHeight)
	: Shape(pos, dir), halfWidth(hWidth), halfHeight(hHeight)
{}

double Rect::getWidth() const
{
	return this->halfWidth * 2.0;
}

double Rect::getHeight() const
{
	return this->halfHeight * 2.0;
}
