#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>

using namespace std;

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define VI vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define all(v) v.begin(), v.end()

#define NMAX 12
#define MMAX 1030

int d[NMAX][MMAX];
string a[NMAX];
bool can2[MMAX][MMAX];
bool can[MMAX];
bool canp[NMAX][MMAX];
int ones[MMAX];
int n, m;

int getOnes(int v)
{
	int ret = 0;
	while (v)
	{
		ret += v & 1;
		v >>= 1;
	}
	return ret;
}

bool isCan(int mask)
{
	forn(i, m - 1)
	{
		if ( (mask & (1 << i)) && (mask & (1 << (i + 1))) ) return false;
	}
	return true;
}

bool isCanP(int row, int mask)
{
	forn(i, m)
	{
		if (a[row][i] == 'x' && (mask & (1 << i))) return false;
	}
	return true;
}

bool isCan2(int mask1, int mask2)
{
	forn(i, m)
	{
		if (mask2 & (1 << i))
		{
			if (i > 0 && (mask1 & (1 << (i - 1)))) return false;
			if (i < m - 1 && (mask1 & (1 << (i + 1)))) return false;
		}
	}
	return true;
}

void solve(int tc)
{
	cerr << tc << endl;
	cin >> n >> m;
	forn(i, n) cin >> a[i];
	int M = (1 << m);
	forn(i, M)
	{
		can[i] = isCan(i);
		ones[i] = getOnes(i);
		forn(j, n)
		{
			canp[j][i] = isCanP(j, i);
		}
	}		
	memset(can2, 0, sizeof(can2));
	forn(i, M)
	{
		if (!can[i]) continue;
		forn(j, M)
		{
			if (!can[j]) continue;
			can2[i][j] = isCan2(i, j);
		}
	}
	memset(d, 255, sizeof(d));
	d[0][0] = 0;
	forn(i, n)
	{
		forn(j, M)
		{
			if (d[i][j] == -1) continue;
			forn(k, M)
			{
				if (!can2[j][k]) continue;
				if (!canp[i][k]) continue;
				d[i + 1][k] = max(d[i + 1][k], d[i][j] + ones[k]);
			}
		}
	}
	int ans = -1;
	forn(i, M) ans = max(ans, d[n][i]);
	printf("Case #%d: %d\n", tc, ans);
}

int main()
{
	freopen(CIN_FILE, "rt", stdin);
	freopen(COUT_FILE, "wt", stdout);
	int tc;
	cin >> tc;
	for1(i, tc) solve(i);
	return 0;
}
         	
