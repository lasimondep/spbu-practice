#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

const int MAXN(1e5 + 5);

void delete_duplicates(int a[], int &n) {
	bool f[n];
	memset(f, 0, sizeof f);
	set <int> s;
	int d(0);
	for (int i(0); i < n; ++i)
		if (s.find(a[i]) != s.end())
			f[i] = true, d++;
		else
			s.insert(a[i]);
	int t[n];
	for (int l = 0, k = 0; k < n; ++k)
		if (!f[k])
			t[l++] = a[k];
	n -= d;
	memcpy(a, t, (sizeof (int)) * n);
}

int main() {
	int a[MAXN], n;
	scanf("%d", &n);
	for (int i(0); i < n; ++i)
		scanf("%d", a + i);
	delete_duplicates(a, n);
	for (int i(0); i < n; ++i)
		printf("%d ", a[i]);
	return 0;
}