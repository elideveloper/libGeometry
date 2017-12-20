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
	

	//getShifted
	//getRotated

};
