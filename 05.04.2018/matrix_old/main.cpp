#include <cstdio>
#include "matrix.h"

typedef matrix <int> M;

M a();

int main() {
//	matrix <int, 5, 5> b(1);
	M c(a);
	return 0;
}