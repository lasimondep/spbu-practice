#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN(1e5);

bool lss(pair <int, int> &a, pair <int, int> &b);

int main() {
	int n, w;
	pair <int, int> t[MAXN]; //weight, cost
	scanf("%d%d", &n, &w);
	for (int i(0); i < n; ++i)
		scanf("%d%d", &t[i].first, &t[i].second);
	sort(t, t + n, &lss);
	double ans(0);
	for (int i(0); w && i < n; ++i)
		if (w >= t[i].first)
			w -= t[i].first, ans += t[i].second;
		else {
			ans += (double)w / t[i].first * t[i].second;
			break;
		}
	printf("%.5lf", ans);
	return 0;
}

bool lss(pair <int, int> &a, pair <int, int> &b) {
	return (double)a.second / a.first > (double)b.second / b.first;
}