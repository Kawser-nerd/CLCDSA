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

#define CMAX 12016
#define SH 3002
#define NMAX 5000000

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Point
{
	int x, y;
	Point() {};
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

bool b[CMAX][CMAX], pp[CMAX][CMAX];
Point p[NMAX];
int n;
string path;

void draw(int x1, int y1, int x2, int y2, int dir)
{
	x1 += SH;
	y1 += SH;
	x2 += SH;
	y2 += SH;
	x1 *= 2;
	y1 *= 2;
	x2 *= 2;
	y2 *= 2;
	if (x1 == x2)
	{
		while (true)
		{
			b[x1][y1] = true;
			y1 += dy[dir];
			if (y1 == y2) break;
		}	
	}
	else
	{
		while (true)
		{
			b[x1][y1] = true;
			x1 += dx[dir];
			if (x1 == x2) break;
		}			
	}
}

int getSq()
{
	long long s = 0;
	forn(i, n)
	{
		s += (p[i].x - p[i + 1].x) * (p[i].y + p[i + 1].y);
	}
	if (s < 0) s = -s;
	s /= 2;
	return (int)s;
}

void solve(int tc)
{
	cerr << tc << endl;
	forn(i, CMAX) forn(j, CMAX) b[i][j] = false;
	n = 1;
	p[0].x = 0;
	p[0].y = 0;
	int L;
	cin >> L;
	int x = 0, y = 0, dir = 0;

	path = "";
	forn(it, L)
	{
		string s;
		int rep;
		cin >> s >> rep;
		forn(i, rep) path += s;
	}
	int len = (int)path.size();
	int l = 0;
	while (l < len)
	{
		if (path[l] == 'R')
		{
			dir = (dir + 1) % 4;
			++l;
		}
		else
		if (path[l] == 'L')
		{
			dir = (dir + 3) % 4;
			++l;
		}
		else
		{
			int px = x, py = y;
			while (l < len && path[l] == 'F')
			{
				x += dx[dir];
				y += dy[dir];
				++l;
			}
			draw(px, py, x, y, dir);
			p[n].x = x;
			p[n].y = y;
			++n;			
		}
	}

	p[n] = p[0];
	int ans = 0;

	forn(i, CMAX) forn(j, CMAX) pp[i][j] = false;

	for (int i = 1; i < CMAX; i += 2)
	{
		int mn = -1, mx = -1;
		forn(j, CMAX)
		{
			if (b[i][j])
			{
				if (mn == -1) mn = j;
				mx = j;
			}
		}
		for (int j = 1; j < CMAX; j += 2)
		{
			if (j >= mn && j <= mx) pp[i][j] = true;
		}
	}

	for (int j = 1; j < CMAX; j += 2)
	{
		int mn = -1, mx = -1;
		forn(i, CMAX)
		{
			if (b[i][j])
			{
				if (mn == -1) mn = i;
				mx = i;
			}
		}
		for (int i = 1; i < CMAX; i += 2)
		{
			if (i >= mn && i <= mx) pp[i][j] = true;
		}
	}

	for (int i = 1; i < CMAX; i += 2)
	{
		for (int j = 1; j < CMAX; j += 2)
		{
			if (pp[i][j]) ++ans;
		}
	}

	ans -= getSq();

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
         	
