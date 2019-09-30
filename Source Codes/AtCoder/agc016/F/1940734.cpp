#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <ctime>
#include<complex>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int L = 16;
const int MAX = 1 << L;
const int MOD = 1000 * 1000 * 1000 + 7;

int G[MAX];
LL dp[MAX];
int n;
int CNT[MAX];

bool isOk(int maskTo, int subMask)
{
	int b1 = (subMask & 1) ? 1 : 0;
	int b2 = (subMask & 2) ? 1 : 0;
	if (b1 != b2) return false;
	FOR(i, 0, n)
	{
		if (maskTo & (1 << i))
		{
			if ((G[i] & subMask) == 0) return false;
		}
	}

	return true;
}

LL f(int maskTo, int subMask)
{
	LL ans = 1;
	FOR(i, 0, n)
	{
		if (((1 << i) & maskTo) != 0)
		{
			int cnt = CNT[G[i] & subMask];
			ans = (ans * ((1 << cnt) - 1) + MOD) % MOD;
		}

		if (((1 << i) & subMask) != 0)
		{
			int cnt = CNT[G[i] & maskTo];
			ans = (ans * (1 << cnt)) % MOD;
		}
	}

	return ans;
}

LL calc(int mask)
{
	if (dp[mask] != -1) return dp[mask];

	dp[mask] = 0;
	for (int subMask = mask; subMask > 0; subMask = (subMask - 1) & mask)
	{
		int maskTo = mask ^ subMask;
		if (!isOk(maskTo, subMask)) continue;
		LL mult = f(maskTo, subMask);
		//cout << "??" << subMask << " " << mult << endl;
		
		dp[mask] = (dp[mask] + mult * calc(maskTo)) % MOD;
	}

	return dp[mask];
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int m;
	cin >> n >> m;

	FOR(mask, 0, 1 << n)
	{
		FOR(k, 0, n)
		{
			if (mask & (1 << k)) CNT[mask]++;
		}
	}

	FILL(dp, -1);
	dp[0] = 1;

	FOR(i, 0, m)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		G[x] |= 1 << y;
	}

	LL ans = 1;
	FOR(i, 0, m)
	{
		ans = (ans + ans) % MOD;
	}

	LL t = calc((1 << n) - 1);
	ans = (ans - t + MOD) % MOD;
	cout << ans << endl;
}