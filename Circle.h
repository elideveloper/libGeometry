#pragma once

#include "Shape.h"
#include "Rect.h"

class Circle : public Shape {
	double radius;
public:
	Circle();
	Circle(const Circle& circle);
	Circle(const Vec2D& pos, const Vec2D& dir, double radius);
	double getRadius() const;
	double getArea() const;
	bool isInclude(const Vec2D& point) const;
	Circle getShifted(const Vec2D& vector) const;
	Circle getRotated(const Vec2D& vector) const;
	Circle getRotated(double angle) const;
	bool isIntersect(const Circle& circle) const;
	bool isIntersect(const Rect& rect) const;
};
