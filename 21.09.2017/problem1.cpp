#include <cstdio>

const int MAXN(100);

int main() {
 	int n, m, k(0), *a = new int [MAXN * MAXN];
 	scanf("%d%d", &n, &m);
 	for (int i(0); i < n; ++i)
 		for (int j(0); j < m; ++j)
 			a[i * m + j] = ++k;
 	for (int i(0); i < n; ++i) {
		for (int j(0); j < m; ++j)
			printf(k > 0xf ? k > 0xff ? k > 0xfff ? "%4x " : "%3x " : "%2x " : "%x ", a[i * m + j]);
		putchar('\n');
	}
	return 0;
}