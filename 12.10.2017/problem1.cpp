/**
abc5d
fgedr
amc5k
d in {0, 9}; d = 0 -> r = k; d = 9 -> r > 0;
e in {0, 9}; e = 0 -> 5 + d < 10 -> d = 0; e = 9 -> 5 + d > 9 -> d = 9; e = d;
a + f < 10 -> f = 0 -> b + g < 10 - (c + e) % 10;
*/

#include <cstdio>

void print(int d) {
	for (int r(d > 0); r < 10; ++r)
		for (int c(0); c < 10; ++c)
			for (int b(0); b < 10; ++b)
				for (int g(0); g + b < 10 - (c + d) % 10; ++g)
					for (int a(0); a < 10; ++a)
						printf("%d%d%d5%d\n0%d%d%d%d\n%d%d%d5%d\n\n", a, b, c, d, g, d, d, r, a, b + g, c, r - (d > 0));
}

int main() {
	print(0);
	print(9);
	return 0;
}