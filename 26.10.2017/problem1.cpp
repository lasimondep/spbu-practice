#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

const int MAXN(1e5 + 5);

int main() {
	int a, b, n;
	pair <int, int> seg[MAXN];
	scanf("%d%d%d", &n, &a, &b);
	for (int i(0); i < n; ++i)
		scanf("%d%d", &seg[i].first, &seg[i].second);
	sort(seg, seg + n);
	int k(0);
	for (; seg[k].first < a; ++k);
	stack <pair <int, int> > s;
	pair <int, int> now;
	for (; k < n; ++k) {
		if (seg[k].second > b)
			continue;
		if (s.empty())
			s.push(seg[k]);
		else {
			now = s.top();
			if (now.first <= seg[k].first && seg[k].second <= now.second) {
				s.pop();
				s.push(seg[k]);
			}
			if (now.second < seg[k].first)
				s.push(seg[k]);
		}
	}
	printf("%d\n", s.size());
	while (!s.empty()) {
		printf("[%d, %d]\n", s.top().first, s.top().second);
		s.pop();
	}
	return 0;
}