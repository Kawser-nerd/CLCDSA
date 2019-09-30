#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int n, k, ansx;
double p[1000], q[1000], dp[1000][1000], ans;

void doit() {
	scanf("%d%d", &n, &k);
	// printf("%d %d\n",n, k );
	for (int i = 0; i < n; i++)
		scanf("%lf", &p[i]);
	sort(p, p + n);
	ans = 0;
	int mid = 0;
	for (int i = 0; i < n; i++)
		if (p[i] < 0.5)
			mid = i;
	for (int ii = 0; ii <= k && ii <= mid + 1; ii++) {
		if (n - mid - 1 < k - ii)
			continue;
		int len = 0;
		for (int j = mid - ii + 1; j <= mid; j++)
			q[++len] = p[j];
		for (int j = mid + 1; len < k; j++)
			q[++len] = p[j];
		for (int i = 0; i <= k; i++)
			for (int j = 0; j <= k; j++)
				dp[i][j] = 0;
		dp[0][0] = 1;
		for (int i = 1; i <= k; i++)
			for (int j = 0; j < i; j++)
				dp[i][j] += dp[i - 1][j] * (1 - q[i]), dp[i][j + 1] += dp[i - 1][j] * q[i];
		if (dp[k][k / 2] > ans) {
			ans = dp[k][k / 2];
			// ansx = S;
		}
	}
	for (int ii = 0; ii <= k; ii++) {
		int len = 0;
		for (int j = 0; j < ii; j++)
			q[++len] = p[j];
		for (int j = n - 1; len < k; j--)
			q[++len] = p[j];
		for (int i = 0; i <= k; i++)
			for (int j = 0; j <= k; j++)
				dp[i][j] = 0;
		dp[0][0] = 1;
		for (int i = 1; i <= k; i++)
			for (int j = 0; j < i; j++)
				dp[i][j] += dp[i - 1][j] * (1 - q[i]), dp[i][j + 1] += dp[i - 1][j] * q[i];
		if (dp[k][k / 2] > ans) {
			ans = dp[k][k / 2];
			// ansx = S;
		}
	}
	// for (int S = 0;  S < (1 << n); S += 1) {
	// 	int cnt = 0;
	// 	for (int i = 0; i < n; i++)
	// 		if (S & (1 << i))
	// 			cnt += 1;
	// 	if (cnt != k)
	// 		continue;
	// 	int len = 0;
	// 	for (int i = 0; i < n; i++)
	// 		if (S & (1 << i))
	// 			q[++len] = p[i];
	// 	// printf("%lf %lf\n", q[1], q[2]);
	// 	// memset(dp, 0, sizeof dp);
	// 	for (int i = 0; i <= k; i++)
	// 		for (int j = 0; j <= k; j++)
	// 			dp[i][j] = 0;
	// 	dp[0][0] = 1;
	// 	for (int i = 1; i <= k; i++)
	// 		for (int j = 0; j < i; j++)
	// 			dp[i][j] += dp[i - 1][j] * (1 - q[i]), dp[i][j + 1] += dp[i - 1][j] * q[i];
	// 	if (dp[k][k / 2] > ans) {
	// 		ans = dp[k][k / 2];
	// 		ansx = S;
	// 	}
	// }
	// for (int i = 0; i < n; i++)
	// 	if ((1 << i) & ansx)
	// 		printf("%d ", i);
	// printf("\n");
	printf("%.8lf\n", ans);
}

int main() {
	// freopen("B-small-attempt0.in", "r", stdin);
	// freopen("b2.out", "w", stdout);
	int T;
	scanf("%d", &T);
	// printf("\n");
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: " , i);
		doit();
		// while (1);
	}
}
