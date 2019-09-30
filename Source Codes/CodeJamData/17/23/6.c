#include <stdio.h>
#include <string.h>

#define N 110

typedef long long ll;

ll e[N], s[N], cd[N], d[N][N];
double dp[N];

void solve(int case_no) {
	int i, j, n, q, u, v;

	scanf("%d%d", &n, &q);
	for (i = 1; i <= n; i++)
		scanf("%lld%lld", &e[i], &s[i]);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%lld", &d[i][j]);
	while (q--)
		scanf("%d%d", &u, &v);

	cd[1] = 0LL;
	for (i = 1; i < n; i++)
		cd[i+1] = cd[i] + d[i][i+1];

	memset(dp, 0x7f, sizeof dp);
	dp[1] = 0.0;
	for (i = 1; i < n; i++)
		for (j = i + 1; j <= n; j++)
			if (cd[i] + e[i] >= cd[j]) {
				ll dist = cd[j] - cd[i];
				double travel_time = 1.0 * dist / s[i];
				if (dp[i] + travel_time < dp[j])
					dp[j] = dp[i] + travel_time;
			}

	printf("Case #%d: %.12f\n", case_no, dp[n]);
}

int main(int argc, char** argv) {
	int case_no, t;

	scanf("%d", &t);
	for (case_no = 1; case_no <= t; case_no++)
		solve(case_no);

	return 0;
}