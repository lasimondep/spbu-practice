#include <cstdio>
#include <algorithm>

inline int lcm(int a, int b);

class Q {
	private:
	int n, m;
	void norm() {
		int d(std::__gcd(n, m));
		n /= d, m /= d;
	}
	public:
	Q() {}
	Q(int N, int M) : n(N), m(M) {
		norm();
		if (m < 0)
			m *= -1, n *= -1;
	}
	void print() {
		if (m == 1)
			printf("%d", n);
		else
			printf("%d/%d", n, m);
	}
	Q operator+(const Q sec) {
		int l(lcm(m, sec.m));
		int x(l / m), y(l / sec.m);
		return Q(n * x + sec.n * y, l);
	}
	Q operator-(const Q sec) {
		int l(lcm(m, sec.m));
		int x(l / m), y(l / sec.m);
		return Q(n * x - sec.n * y, l);
	}
	Q operator*(const Q sec) {
		return Q(n * sec.n, m * sec.m);
	}
	Q operator/(const Q sec) {
		return Q(n * sec.m, m * sec.n);
	}
};

int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	Q p(a, b), q(c, d);
	printf("p = ");
	p.print();
	printf(" q = ");
	q.print();
	printf("\np + q = ");
	(p + q).print();
	printf("\np - q = ");
	(p - q).print();
	printf("\np * q = ");
	(p * q).print();
	printf("\np / q = ");
	(p / q).print();
	return 0;
}

inline int lcm(int a, int b) {
	return (a * b) / std::__gcd(a, b);
}