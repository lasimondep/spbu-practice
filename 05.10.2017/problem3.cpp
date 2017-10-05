#include <cstdio>
#include <cstring>

const int MAXN(105);

int main() {
	int n, a[MAXN][MAXN];
	scanf("%d", &n);
	memset(a, 0, sizeof a);
	a[n >> 1][n >> 1] = (n >> 1) + 1;
	for (int k(0), d(1); k < n >> 1; ++k, ++d)
		for (int i(k); i < n - k; ++i)
			a[k][i] = a[i][k] = a[n - 1 - k][i] = a[i][n - 1 - k] = d;
	for (int i(0); i < n; ++i) {
		for (int j(0); j < n; ++j)
			printf("%d ", a[i][j]);
		putchar('\n');
	}
	return 0;
}