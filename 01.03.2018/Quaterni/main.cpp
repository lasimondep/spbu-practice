#include <cstdio>
#include <cmath>
#include "quaterni.h"
#include "func.h"

int main() {
	quaterni a(0, 2, -1, -3), b(1, 3, -2, 5), c;
	a.print("a: ");
	b.print("b: ");
	(!a).print("conj a: ");
	printf("norm a: %.4f\n", sqrt(a.norm()));
	(a + b).print("a + b: ");
	(a - b).print("a - b: ");
	(a * b).print("a * b: ");
	(b * a).print("b * a: ");
	(a / b).print("a / b: ");
	(b / a).print("b / a: ");
	return 0;
}