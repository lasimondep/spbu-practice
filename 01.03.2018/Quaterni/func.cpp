#include "quaterni.h"
#include "func.h"

quaterni operator+(quaterni a, const quaterni &b) {
	a += b;
	return a;
}

quaterni operator*(quaterni a, const quaterni &b) {
	a *= b;
	return a;
}

quaterni operator*(quaterni a, const double b) {
	a *= b;
	return a;
}

quaterni operator*(const double a, quaterni b) {
	return b * a;
}

quaterni operator-(quaterni a, const quaterni &b) {
	a -= b;
	return a;
}

quaterni operator/(quaterni a, const quaterni &b) {
	a /= b;
	return a;
}
