#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <ctime>
using namespace std;

typedef long long int64;
int C[1024][1024];
const int mod = 100003;
int Comb(int m, int n)
{
	if (m < 0 || n < 0) return 0;
	if (n == 0 || n == m) return 1;
	if (n > m ) return 0;
	int x = C[m][n];
	if (x != -1) return x;
	int t = Comb(m-1, n-1) + Comb(m-1, n);
	return C[m][n] = t % mod;
}


int dp[512][512];

int cal(int i, int j)
{
	if (j == 1) return 1;
	//if (i == 2 && j == 1) return 1;
	if (j > i - 1) return 0;
	int& t = dp[i][j];
	if (t != -1) return t;
	int ans = 0;
	for (int x = 1; x < j; ++x)
	{
		int64 tmp = cal(j, x);
		tmp = tmp * Comb(i - j - 1, j - x - 1);
		tmp %= mod;
		ans = ans + tmp;
		ans %= mod;
	}
	return t = ans;
}
int main()
{
	memset(C, 255, sizeof C);
	memset(dp, 255, sizeof dp);
	int cas;scanf("%d", &cas);
	int id = 1;
	while (cas--)
	{
		int n;scanf("%d", &n);
		int ans = 0;
		for (int i = 1; i < n; ++i) ans = (ans + cal(n, i)) % mod;
		printf("Case #%d: %d\n", id++, ans);
	}
	return 0;
}
