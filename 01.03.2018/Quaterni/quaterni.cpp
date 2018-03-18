#include <cstdio>
#include "quaterni.h"
#include "func.h"

quaterni &quaterni::operator+=(const quaterni &x) {
	a += x.a, b += x.b, c += x.c, d += x.d;
	return *this;
}

quaterni &quaterni::operator*=(const quaterni &x) {
	quaterni t(*this);
	a = t.a * x.a - t.b * x.b - t.c * x.c - t.d * x.d;
	b = t.a * x.b + t.b * x.a + t.c * x.d - t.d * x.c;
	c = t.a * x.c + t.c * x.a + t.d * x.b - t.b * x.d;
	d = t.a * x.d + t.d * x.a + t.b * x.c - t.c * x.b;
	return *this;
}

quaterni &quaterni::operator*=(const double x) {
	a *= x, b *= x, c *= x, d *= x;
	return *this;
}

quaterni quaterni::operator-() {
	return quaterni(-a, -b, -c, -d);
}

quaterni &quaterni::operator-=(const quaterni &x) {
	a -= x.a, b -= x.b, c -= x.c, d -= x.d;
	return *this;
}

quaterni quaterni::operator!() {
	return quaterni(a, -b, -c, -d);
}

double quaterni::norm() {
	return a * a + b * b + c * c + d * d;
}

quaterni &quaterni::operator/=(const quaterni &x) {
	quaterni t(x);
	*this *= !t * (1 / t.norm());
	return *this;
}

void quaterni::print(const char msg[]) {
	printf("%s%.4f %.4f %.4f %.4f\n", msg, a, b, c, d);
}