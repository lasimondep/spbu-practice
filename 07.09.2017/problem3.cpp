#include <cstdio>
#include <algorithm>

const int MAXN(100), INF(1e5);

int main() {
	int n, m, x, y, a[MAXN][MAXN], d[MAXN][MAXN];
	memset(a, 0, sizeof a), memset(d, 0, sizeof d);
	scanf("%d%d%d%d", &n, &m, &x, &y);
	x = n - x;
	for (int i(1); i <= n; ++i)
		for (int j(1); j <= m; ++j)
			scanf("%d", &a[i][j]);
	for (int i(0); i <= n; ++i)
		d[i][y - 1] = INF;
	for (int i(0); i <= m; ++i)
		d[x + 1][i] = INF;
	d[x + 1][y] = 0;
	for (int i(x); i > 0; --i)
		for (int j(y); j <= m; ++j)
			d[i][j] = a[i][j] + std::min(d[i][j - 1], d[i + 1][j]);
	printf("%d", d[1][m]);
	return 0;
}
