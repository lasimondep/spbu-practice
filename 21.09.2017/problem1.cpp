#include <cstdio>

const int MAXN(100);

int main() {
 	int n, m, *a = new int [MAXN * MAXN];
 	scanf("%d%d", &n, &m);
 	for (int i(0); i < n; ++i)
 		for (int j(0); j < m; ++j)
 			scanf("%d", a + i * m + j);
 	for (int i(0); i < n; ++i) {
		for (int j(0); j < m; ++j)
			printf("%d ", a[i * m + j]);
		putchar('\n');
	}
	return 0;
}