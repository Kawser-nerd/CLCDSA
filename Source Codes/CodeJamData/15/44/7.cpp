/*
	Author: elfness@UESTC
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long LL;
const int V = 110;
const int P = 1000000007;
int Pow(int x, int y)
{
	int ret = 1;
	while(y)
	{
		if(y & 1) ret = (LL) ret * x % P;
		x = (LL) x * x % P; y /= 2;
	}
	return ret;
}
int gcd(int x, int y)
{
	if(!x) return y;
	if(!y) return x;
	return gcd(y, x % y);
}
int lcm(int x, int y)
{
	return x * y / gcd(x,y);
}
int dp[V][20][2];
int _, n, m;
int Cal()
{
	memset(dp, 0, sizeof(dp));
	dp[0][1][0] = dp[0][1][1] = 1;
	for(int i = 0; i < n; ++i)
	for(int j = 0; j <= 12; ++j)
	if(dp[i][j])
	{
		dp[i + 2][j][1] += dp[i][j][0];
		dp[i + 2][j][1] %= P;
		if(m % 1 == 0)
		{
			dp[i + 1][lcm(j, 1)][0] += dp[i][j][1];
			dp[i + 1][lcm(j, 1)][0] %= P;
		}
		if(m % 3 == 0)
		{
			dp[i + 2][lcm(j, 3)][0] += (LL)dp[i][j][1] * 3 % P;
			dp[i + 2][lcm(j, 3)][0] %= P;
		}
		if(m % 6 == 0)
		{
			dp[i + 2][lcm(j, 6)][0] += (LL)dp[i][j][1] * 6 % P;
			dp[i + 2][lcm(j, 6)][0] %= P;
		}
		if(m % 4 == 0)
		{
			dp[i + 3][lcm(j, 4)][0] += (LL)dp[i][j][1] * 4 % P;
			dp[i + 3][lcm(j, 4)][0] %= P;
		}
	}
	int ret = 0;
	for(int i = 1; i <= 12; ++i)
	{
		ret += (LL)(dp[n][i][0] + dp[n][i][1]) * Pow(i, P - 2) % P;
		ret %= P;
	}
	return ret;
}
int main()
{
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
	scanf("%d", &_);
	for(int ca = 1; ca <= _; ++ca)
	{
		scanf("%d%d", &n, &m);
		printf("Case #%d: %d\n", ca, Cal());
	}
	return 0;
}
