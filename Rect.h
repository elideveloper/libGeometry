#pragma once

#include "Shape.h"

class Rect : public Shape {
	double halfWidth;
	double halfHeight;
public:
	Rect();
	Rect(const Rect& rect);
	Rect(const Vec2D& pos, const Vec2D& dir, double hWidth, double hHeight);
	double getWidth() const;
	double getHeight() const;
	double getHalfDiag() const;
	double getArea() const;
	bool isInclude(const Vec2D& point) const;
	Rect getShifted(const Vec2D& vector) const;
	Rect getRotated(const Vec2D& vector) const;
	Rect getRotated(double angle) const;
	// TODO intersections with other shapes
};
