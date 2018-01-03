#include "Rect.h"
#include "Circle.h"

#include <iostream>

using namespace std;

// возможно функции типа shift() и set(), мен€ющие состо€ни€ объектов,
// будут возвращать указатель на себ€, чтобы выстраивать цепочку методов - подумать

int main() {

	Vec2D vec(-2.35619);
	Vec2D vec1(-1.0, -3.0);
	Vec2D vec2(2.0, 4.0);

	cout << vec1.add(vec2).getReversed().getDistanceSquare(vec1) << endl;
	vec1.add(vec2).getReversed().print();
	vec.print();

	Circle c1(Vec2D(2.0, 2.0), Vec2D(), 1.5);
	Circle c2(Vec2D(0.0, 0.0), Vec2D(), 1.33);

	cout << c1.isIntersect(c2) << endl;
	cout << c1.getPosition().getDistance(c2.getPosition()) << endl;

	Rect rect(Vec2D(1.0, 1.0), Vec2D(0.0), 3.0, 1.0);
	std::vector<Vec2D> verts = rect.getVertices();
	for (Vec2D v : verts) {
		v.print();
	}

	Rect rect2(Vec2D(-10.0, -0.999), Vec2D(0.0), 3.0, 1.0);

	cout << rect.isIntersect(rect2) << endl;

	system("pause");
	return 0;
}