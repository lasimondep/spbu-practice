#include <cstdio>

const int MAXN(1000);

inline void swap(int &x, int &y) {
	x ^= y ^= x ^= y;
}

int fsearch(int a[], int r, int k);

int main() {
	int n, a[MAXN];
	scanf("%d", &n);
	for (int i(0); i < n; ++i)
		scanf("%d", a + i);
	int m(fsearch(a, n - 1, n / 2)), ans(0);
	for (int i(0); i < n; ++i)
		ans += (a[i] * 2 <= m);
	printf("%d", ans);
	return 0;
}

int fsearch(int a[], int r, int k) {
	int l(0);
	for (;;) {
		if (l >= r - 1) {
			if (a[r] < a[l])
				swap(a[l], a[r]);
			return a[k];
		}
		swap(a[(l + r) >> 1], a[l + 1]);
		if (a[l] > a[r])
			swap(a[l], a[r]);
		if (a[l + 1] > a[r])
			swap(a[l + 1], a[r]);
		if (a[l] > a[l + 1])
			swap(a[l], a[l + 1]);
		int t(a[l + 1]), i(l + 1), j(r);
		for (;;) {
			while (a[++i] < t);
			while (a[--j] > t);
			if (i > j)
				break;
			swap(a[i], a[j]);
		}
		a[l + 1] = a[j];
		a[j] = t;
		if (k <= j)
			r = j - 1;
		if (k >= j)
			l = i;
	}
}
