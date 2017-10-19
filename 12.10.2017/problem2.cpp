#ifdef __WIN32
	#define I64d "%I64d"
#else
	#define I64d "%lld"
#endif

#include <cstdio>

long long p;

inline long long pw(long long a, long long k) {
	long long res(1);
	while (k)
		if (k & 1)
			res = res * a % p, k--;
		else
			a = a * a % p, k >>= 1;
	return res % p;
}

inline bool prime(long long p) {
	bool res(true);
	for (long long d(2); res && d * d <= p; ++d)
		res &= p % d > 0;
	return res;
}

inline bool leg_symb(long long a) {
	a = pw(a, (p - 1) >> 1);
	return (a == 1);
}

int main() {
	long long a, s, z, y, t, b, c;
	int i, n, e;
	bool f;
	do {
		printf("p = ");
		scanf(I64d, &p);
		f = prime(p);
		if (!f)
			printf("p is not odd prime!\n");
	} while (!f);
	for (z = 3; (z < p) && leg_symb(z); ++z);
	do {
		printf("a = ");
		scanf(I64d, &a);
		f = leg_symb(a);
		if (!f)
			printf("a is not quadratic residue!\n");
	} while (!f);
	for (e = 1; !((p - 1) % (1 << e)); ++e);
	s = (p - 1) / (1 << --e);
	y = pw(a, (s + 1) >> 1), t = pw(a, s);
	printf("e = %d, s = " I64d "\nz = " I64d "\ny = " I64d ", t = " I64d "\n\n", e, s, z, y, t);
	long long tt;
	n = e, c = pw(z, s);
	while (t != 1) {
		tt = t;
		for (i = 0; tt != 1; ++i)
			tt = (tt * tt) % p;
		printf("t != 1, i = %d\n", i);
		b = pw(c, 1 << (n - 1 - i));
		y = y * b % p, c = b * b % p,  n = i;
		t = t * c % p;
		printf("b = " I64d "\ny = " I64d ", c = " I64d ", t = " I64d ", n = %d\n--------------------\n", b, y, c, t, n);
	}
	printf("t = 1 => x := +-y = " I64d ", " I64d, y, p - y);
	return 0;
}