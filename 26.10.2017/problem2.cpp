#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN(10005);

int main() {
	int x, c[MAXN];
	scanf("%d", &x);
	for (int i(0); (long long)i * i <= x; ++i)
		c[i] = i * i;
	int dp[x + 1];
	memset(dp, 127, sizeof dp);
	dp[0] = 0, dp[1] = 1;
	for (int s(2); s <= x; ++s)
		for (int k(0); s >= c[k]; ++k)
			dp[s] = std::min(dp[s], dp[s - c[k]] + 1);
	printf("%d\n", dp[x]);
	for (int s(x); s > 0;)
		for (int k(0); s >= c[k]; ++k)
			if (dp[s] - 1 == dp[s - c[k]])
				printf("%d ", c[k]), s -= c[k];
	return 0;
}