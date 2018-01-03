#include "Circle.h"

Circle::Circle()
{}

Circle::Circle(const Circle& circle) : Shape(circle.position, circle.direction), radius(circle.radius)
{}

Circle::Circle(const Vec2D& pos, const Vec2D& dir, double radius) : Shape(pos, dir), radius(radius)
{}

double Circle::getRadius() const
{
	return this->radius;
}

double Circle::getArea() const
{
	return PI * this->radius * this->radius;
}

bool Circle::isInclude(const Vec2D& point) const
{
	return (this->position.getDistance(point) <= this->radius) ? true : false;
}

Circle Circle::getShifted(const Vec2D& vector) const
{
	return Circle(this->position.add(vector), this->direction, this->radius);
}

Circle Circle::getRotated(const Vec2D& vector) const
{
	return Circle(this->position, this->direction.add(vector.getUnit()).getUnit(), this->radius);
}

Circle Circle::getRotated(double angle) const
{
	return Circle(this->position, this->direction.getRotated(angle), this->radius);
}

bool Circle::isIntersect(const Circle& circle) const
{
	return this->position.getDistance(circle.position) <= circle.getRadius() + this->getRadius();
}

bool Circle::isIntersect(const Rect& rect) const
{
	if (rect.getHalfDiag() + this->radius < rect.getPosition().getDistance(this->position)) return false;
	if (MIN(rect.getHeight(), rect.getWidth()) + this->radius >= rect.getPosition().getDistance(this->position)) return true;
	// TODO
	std::vector<Vec2D> vertices = rect.getVertices();
	for (Vec2D v : vertices) if (this->isInclude(v)) return true;
	return false;
}
