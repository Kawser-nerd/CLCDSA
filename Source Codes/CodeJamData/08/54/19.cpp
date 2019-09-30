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

#define NMAX 105

int d[NMAX][NMAX];
int n, m;
bool bad[NMAX][NMAX];

void solve(int tc)
{
	cerr << tc << endl;
	int r;
	cin >> n >> m >> r;
	forn(i, n) forn(j, m) bad[i][j] = false;
	int x, y;
	forn(i, r)
	{
		cin >> x >> y;
		--x;
		--y;
		bad[x][y] = true;
	}
	d[0][0] = 1;
	forn(i, n)
	{
		forn(j, m)
		{
			if (i == 0 && j == 0) continue;
			d[i][j] = 0;
			if (bad[i][j]) continue;
			if (i - 1 >= 0 && j - 2 >= 0) d[i][j] += d[i - 1][j - 2];
			if (i - 2 >= 0 && j - 1 >= 0) d[i][j] += d[i - 2][j - 1];
			d[i][j] %= 10007;
		}
	}
	printf("Case #%d: %d\n", tc, d[n - 1][m - 1]);
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
         	
