#include <cstdio>
#include <cstring>

const int MAXK(105);

int main() {
	int k, n, d[MAXK];
	memset(d, 0, sizeof d);
	d[0] = 1;
	scanf("%d%d", &n, &k);
	for (int i(0); i < k; ++i)
		for (int j(1); j < k - i; ++j)
			d[i + j] += d[i];
	for (int i(k); i < n; ++i)
		for (int j(1); j < k; ++j)
			d[i % k] += d[(i + k - j) % k];
	printf("%d", d[(n - 1) % k]);
	return 0;
}