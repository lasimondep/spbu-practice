#include <cstdio>
#include <cstdlib>
#include <ctime>

const int MAXN(1000);

inline void swap(int &x, int &y) {
	x ^= y ^= x ^= y;
}

int sel(int a[], int l, int r);
int fsearch(int a[], int r, int k);

int main() {
	srand(time(NULL));
	int n, k, a[MAXN];
	scanf("%d%d", &n, &k);
	for (int i(0); i < n; ++i)
		scanf("%d", a + i);
	int m(fsearch(a, n - 1, n - k - 1));
	printf("%d", m);
	return 0;
}

int sel(int a[], int l, int r) {
	if (l == r)
		return l;
	int m(a[l + rand() % (r - l)]);
	while (l <= r) {
		for (; a[l] < m; ++l);
		for (; a[r] > m; --r);
		if (l <= r) {
			if (a[l] > a[r])
				swap(a[l], a[r]);
			l++, r--;
		}
	}
	return l;
}

int fsearch(int a[], int r, int k) {
	int l(0);
	while (l < r) {
		if (l == r - 1)
			if (a[l] > a[r])
				swap(a[l], a[r]);
		int m(sel(a, l, r));
		if (k < m)
			r = m - 1;
		else
			l = m;
	}
	return a[l];
}