#include "Vec2D.h"

#include <iostream>


int main() {

	Vec2D vec(0.0, 0.0);
	Vec2D vec1(-1.0, -3.0);
	Vec2D vec2(2.0, 4.0);

	vec1.add(vec2).sub(vec).getReversed().print();


	system("pause");
	return 0;
}