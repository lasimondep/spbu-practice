#include <cstdio>
#include <algorithm>
#include <stack>

const int MAXN(1e5 + 5);

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	pair <int, pair<int, int> > req[MAXN]; //cabinet, start time, end time
	for (int i(0); i < n; ++i) {
		scanf("%d%d%d", &req[i].first, &req[i].second.first, &req[i].second.second);
		req[i].second.second += req[i].second.first;
	}
	sort(req, req + n);
	stack <pair <int, int> > s[req[n - 1].first + 1];
	pair <int, int> now;
	for (int k(0); k < n; ++k) {
		if (s[req[k].first].empty())
			s[req[k].first].push(req[k].second);
		else {
			now = s[req[k].first].top();
			if (now.first <= req[k].second.first && req[k].second.second <= now.second) {
				s[req[k].first].pop();
				s[req[k].first].push(req[k].second);
			}
			if (now.second < req[k].second.first)
				s[req[k].first].push(req[k].second);
		}
	}
	int ans(0);
	for (int i(0); i <= req[n - 1].first; ++i)
		ans += s[i].size();
	printf("%d", ans);
	return 0;
}