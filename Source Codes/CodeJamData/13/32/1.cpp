#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ldouble;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const char let[4] = {'N', 'E', 'S', 'W'};

int x, y, dp[2001], len;
char ans[2001];

int solve(const int &x, const int &y)
{
	if (x + y >= 0)
		return (x - y >= 0 ? 1 : 0);
	else
		return (x - y >= 0 ? 2 : 3);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	for (int i = 0; i <= 2000; i++)
		dp[i] = i * (i + 1) / 2;

	int ts; scanf("%d", &ts);
	for (int tst = 0; tst < ts; tst++)
	{
		printf("Case #%d: ", tst + 1);
		scanf("%d%d", &x, &y);
		int t = lower_bound(dp, dp + 2001, abs(x) + abs(y)) - dp;
		while (dp[t] % 2 != (abs(x) + abs(y)) % 2) t++; len = t;
		for (int i = len - 1; i >= 0; i--)
		{
			t = solve(x, y);
			x -= dx[t] * (i + 1), y -= dy[t] * (i + 1), ans[i] = let[t];
		}
		for (int i = 0; i < len; i++)
			printf("%c", ans[i]);
		printf("\n");
	}

	return 0;
}