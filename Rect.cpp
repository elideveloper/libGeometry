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
	std::vector<Vec2D> vertices = this->getVertices();
	int numIntersections = 0;
	int prev = vertices.size() - 1;
	bool isPrevUnder = vertices[prev].getY() < point.getY();
	for (int i = 0; i < vertices.size(); ++i) {
		bool cur_under = vertices[i].getY() < point.getY();
		Vec2D a = vertices[prev].sub(point);
		Vec2D b = vertices[i].sub(point);
		double t = (a.getX()*(b.getY() - a.getY()) - a.getY()*(b.getX() - a.getX()));
		if (cur_under && !isPrevUnder && t > 0) numIntersections += 1;
		if (!cur_under && isPrevUnder && t < 0) numIntersections += 1;
		prev = i;
		isPrevUnder = cur_under;
	}
	return numIntersections % 2 != 0;
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

std::vector<Vec2D> Rect::getVertices() const
{
	Vec2D midRight = this->direction.getScaled(this->halfWidth);
	Vec2D midBottom = this->direction.getRightPerpend().getScaled(this->halfHeight);
	std::vector<Vec2D> vertices; vertices.reserve(4);
	vertices.push_back(midRight.sub(midBottom).add(this->position)); vertices.push_back(midRight.add(midBottom).add(this->position));
	vertices.push_back(midRight.getReversed().add(midBottom).add(this->position)); vertices.push_back(midRight.getReversed().sub(midBottom).add(this->position));
	return vertices;
}

bool Rect::isIntersect(const Rect& rect) const
{
	std::vector<Vec2D> vertices = rect.getVertices();
	for (Vec2D v : vertices) if (this->isInclude(v)) return true;
	return false;
}

bool Rect::isIntersect(const Circle& circle) const
{
	return circle.isIntersect(*this);
}
