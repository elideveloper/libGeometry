#include "Vec2D.h"

#include <iostream>

using namespace std;

int main() {

	Vec2D vec(-2.35619);
	Vec2D vec1(-1.0, -3.0);
	Vec2D vec2(2.0, 4.0);

	cout << vec1.add(vec2).getReversed().getDistanceSquare(vec1) << endl;
	vec1.add(vec2).getReversed().print();
	vec.print();

	system("pause");
	return 0;
}