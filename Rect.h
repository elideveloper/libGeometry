#pragma once

#include "Vec2D.h"

class Rect {
	Vec2D position;
	Vec2D direction;
	double halfWidth;
	double halfHeight;
public:
	Rect();
	Rect(const Rect& rect);
	Rect(const Vec2D& pos, const Vec2D& dir, double hWidth, double hHeight);


};
