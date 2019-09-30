#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <memory.h>
using namespace std;


int n;
long long k;
const long long MOD = 1000000009;

int a[510][511];

int fst[511], nxt[511], pow[511], chl[511];

int was[511];

void Dfs1(int v)
{
	int i;
	was[v] = 1;
	pow[v] = 0;
	chl[v] = 0;
	if (v != 1) pow[v] = 1;
	for (i = 1; i <= n; i++)
		if (a[i][v] == 1 && was[i] == 0)
		{
			Dfs1(i);
			pow[v]++;
			chl[v]++;
			nxt[i] = fst[v];
			fst[v] = i;
		}
}

int Load()
{
	memset(a, 0, sizeof(a));
    cin >> n >> k;
	int p, q;
	for (int i = 1; i < n; i++)
	{
		cin >> p >> q;
		a[p][q] = a[q][p] = 1;
	}
	memset(was, 0, sizeof(was));
	memset(fst, 0 ,sizeof(fst));	

	return 0;
}



long long dp[510][511];



long long EGCD(long long a, long long b, long long &x, long long &y)
{
	if (b > a) return EGCD(b,a,y,x);
	else if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		long long d, x1, y1;
		d = EGCD(b, a % b, x1, y1);
		x = y1;
		y = x1 - (b / a) * y1;
		return d;
	}
}


long long Inv(long long i)
{
	long long x, y;
	EGCD(i,MOD, x, y);
	return x;	
}

long long Calc(int v, int bn)
{
	if (dp[v][bn] >= 0) return dp[v][bn];
	if (chl[v] == 0) 
	{
    	return 1;
    }

	if (bn >= k)
	{ 
		dp[v][bn] = 0;
		return 0;
	}
	long long cur = 1;
	int j = pow[v];
	int i;
	for (i = fst[v]; i > 0; i = nxt[i])
		cur = (cur * Calc(i, j)) % MOD;
	// c from k-bn by chl[v];
	int a = chl[v];
	long long b = k-bn;
	if (a > b || a < 0)
	{
		dp[v][bn] = 0;
		return 0;
	}
	long long f;
	for (f = b-a + 1; f <= b; f++)
		cur = (cur * f) % MOD;
	dp[v][bn] = cur;
	return cur;	 
}

void Solve()
{
	memset(dp, -1, sizeof(dp));
	Dfs1(1);
	long long ans = Calc(1, 0);
	cout << ans << "\n";
}

int main()
{
	freopen("c.in", "rt", stdin);
	freopen("c.out", "wt", stdout);
	int tt = 0;
	int nt;
	cin >> nt;
    for (tt = 1; tt <= nt; tt++) 
    {
		Load();
		cout << "Case #" << tt << ": ";
    	Solve();
    }
	return 0;
}


