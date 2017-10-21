#include <cstdio>

inline long long phi(long long x);

int main() {
	long long n;
	scanf("%I64d", &n);
	printf("%I64d", n - phi(n) - 1);
	return 0;
}

inline long long phi(long long x) {
	long long res(x);
	for (long long d(2); d * d <= x; ++d)
		if (!(x % d)) {
			while (!(x % d))
				x /= d;
			res -= res / d;
		}
	if (x > 1)
		res -= res / x;
	return res;
}