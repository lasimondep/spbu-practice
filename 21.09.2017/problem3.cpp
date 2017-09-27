//HeapSort without [] & one argument

#include <cstdio>
#include <malloc.h>

const int MAXN(100);

void sort(int *a);
inline void swap(int *x, int *y);

int main() {
	int *a = (int*)malloc(MAXN * 4);
	scanf("%d", a);
	for (int i(1); i <= *a; ++i)
		scanf("%d", a + i);
	sort(a);
	for (int i(1); i <= *a; ++i)
		printf("%d ", *(a + i));
	return 0;
}

void sort(int *a) {
	int n(*a), l, r, p;
	for (int i(n / 2 + 1); i >= 1; --i) {
		p = i;
		while (p << 1 <= n) {
			l = p << 1, r = (p << 1) + 1;
			if ((r <= n) && (*(a + l) < *(a + r)))
				l = r;
			if (*(a + p) >= *(a + l))
				break;
			swap(a + p, a + l);
			p = l;
		}
	}
	while (n > 1) {
		swap(a + 1, a + n--);
		for (int i(n / 2 + 1); i >= 1; --i) {
			p = i;
			while (p << 1 <= n) {
				l = p << 1, r = (p << 1) + 1;
				if ((r <= n) && (*(a + l) < *(a + r)))
					l = r;
				if (*(a + p) >= *(a + l))
					break;
				swap(a + p, a + l);
				p = l;
			}
		}
	}
}

inline void swap(int *x, int *y) {
	*x ^= *y ^= *x ^= *y;
}