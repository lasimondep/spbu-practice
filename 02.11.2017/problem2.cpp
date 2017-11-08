#include <cstdio>

double f(double a[], int l, int r);

int main() {
	int k;
	scanf("%d", &k);
	int n(1 << k);
	double a[n];
	for (int i(0); i < n; ++i)
		scanf("%lf", a + i);
	printf("%lf", f(a, 0, n));
	return 0;
}

double f(double a[], int l, int r) {
	printf("[%d, %d)\n", l, r);
	if (l == r - 1)
		return a[l];
	double t1(f(a, l, (l + r) >> 1)), t2(f(a, (l + r) >> 1, r));
	return (t1 * t1 * t1 + t2 * t2) / 20;
}