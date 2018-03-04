#include <cstdio>
#include "gauss.h"

void gauss::read(int po) {
	if (po)
		printf("Num of X = ");
	scanf("%d", &n);
	if (po)
		printf("Num of equations = ");
	scanf("%d", &m);
	if (po)
		puts("A[][]:");
	for (int i(0); i < m; ++i)
		for (int j(0); j < n; ++j)
			scanf("%lf", &a[i][j]);
	if (po)
		printf("B[]: ");
	for (int i(0); i < m; ++i)
		scanf("%lf", &a[i][n]);
}