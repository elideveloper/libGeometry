#include "Rect.h"

#include <cmath>

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

double Rect::getHalfDiag() const
{
	return sqrt(this->halfHeight*this->halfHeight + this->halfWidth*this->halfWidth);
}

double Rect::getArea() const
{
	return this->getWidth() * this->getHeight();
}

bool Rect::isInclude(const Vec2D& point) const
{
	if (this->position.getDistance(point) > this->getHalfDiag()) return false;
	if (this->position.getDistance(point) <= MIN(this->halfHeight, this->halfWidth)) return true;
	// TODO
	return false;
}

Rect Rect::getShifted(const Vec2D& vector) const
{
	return Rect(this->position.add(vector), this->direction, this->halfWidth, this->halfHeight);
}

Rect Rect::getRotated(const Vec2D& vector) const
{
	return Rect(this->position, this->direction.add(vector.getUnit()).getUnit(), this->halfWidth, this->halfHeight);
}

Rect Rect::getRotated(double angle) const
{
	return Rect(this->position, this->direction.getRotated(angle), this->halfWidth, this->halfHeight);
}
