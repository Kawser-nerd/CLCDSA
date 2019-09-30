#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define FILE_IN  "D-small-attempt0.in"
#define FILE_OUT "D-small-attempt0.out"

#define MAXN 1003
#define MAXP 10
#define MOD 30031

int n, k, p;
int dp[MAXN][1<<MAXP];

int get(int n, int m) {
	if (n < k)
		return 0;
	int &r = dp[n][m];
	if (r >= 0)
		return r;
	if ((m & 1) == 0)
		return r = 0;
	r = 0;
	int nm = m >> 1;
	for (int i = 0; i < p; ++i) {
		if (nm & (1 << i))
			continue;
		r = (r + get(n-1, nm | (1 << i))) % MOD;
	}
	return r;
}

void solve() {
	scanf("%d%d%d", &n, &k, &p);
	int ms = ((1 << k) - 1);
	fill(dp[0], dp[MAXN], -1);
	dp[k][ms] = 1;
	int r = get(n, ms);
	printf("%d\n", r);
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
