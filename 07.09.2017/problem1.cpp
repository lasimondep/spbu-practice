#include <cstdio>
#include <cstring>

const int MAXN(10), STEP[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

void f(int n, int a[MAXN][MAXN]) {
	int p(3), x(0), y(n - 1), k(1), l(0), nx, ny;
	a[x][y] = 2;
	bool t;
	while (k < n * n) {
		nx = x + STEP[l][0], ny = y + STEP[l][1];
		if (0 <= nx && nx < n && 0 <= ny && ny < n && !a[nx][ny]) {
			x = nx, y = ny, k++;
			a[x][y] = p++;
			for (;; ++p) {
				t = true;
				for (int d(2); t && d * d <= p; ++d)
					t = p % d;
				if (t)
					break;
			}
		}
		else
			l = (l + 1) % 4;
	}
}

int main() {
	int n, a[MAXN][MAXN];
	memset(a, 0, sizeof a);
	scanf("%d", &n);
	f(n, a);
	for (int i(0); i < n; ++i) {
		for (int j(0); j < n; ++j)
			printf("%d ", a[i][j]);
		putchar('\n');
	}
	return 0;
}
