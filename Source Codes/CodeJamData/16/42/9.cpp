#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int T;
int N, K;
double P[202];

double dp[202][202];
double solve(vector<double> ps)
{
	int m = ps.size();
	for (int i = 0; i <= m; ++i) dp[0][i] = 0;
	dp[0][0] = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= m; ++j) dp[i + 1][j] = 0;
		for (int j = 0; j <= m; ++j) {
			dp[i + 1][j] += dp[i][j] * (1 - ps[i]);
			dp[i + 1][j + 1] += dp[i][j] * ps[i];
		}
	}
	return dp[m][m / 2];
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;) {
		scanf("%d%d", &N, &K);
		for (int i = 0; i < N; ++i) scanf("%lf", P + i);
		sort(P, P + N);
		double ans = 0;
		for (int t = 0; t <= K; ++t) {
			vector<double> V;
			for (int i = 0; i < t; ++i) V.push_back(P[i]);
			for (int i = 0; i < K - t; ++i) V.push_back(P[N - 1 - i]);
			ans = max(ans, solve(V));
		}
		printf("Case #%d: %.10f\n", t, ans);
	}

	return 0;
}
