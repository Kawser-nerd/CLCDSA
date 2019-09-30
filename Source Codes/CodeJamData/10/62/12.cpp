#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 28) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n;
int best[1000][1000][2];
bool g[1000][1000];
vector <int> a[1000][1000];

void push (int v, int l, int r)
{
	a[l][r].pb (v);
	a[r][l].pb (v);
	g[l][v] = g[v][l] = 1;
	g[r][v] = g[v][r] = 1;
}

void go (int l, int r)
{
	if (best[l][r][0] != -1)
		return;
	best[l][r][0] = best[l][r][1] = -inf;
	if (g[l][r])
		best[l][r][0] = 0;
	forn (i, a[l][r].size())
	{
		int v = a[l][r][i];
		go (l, v);
		go (v, r);
		int d = best[l][v][0] + best[v][r][0] + 1;
		if (d > best[l][r][0])
		{
			best[l][r][1] = best[l][r][0];
			best[l][r][0] = d;
		}
		else
		if (d > best[l][r][1])
			best[l][r][1] = d;
	}
}

void goggogogog ()
{ 
	seta (g, 0);
	scanf ("%d", &n);
	forn (i, n)
		forn (j, n)
			a[i][j].clear ();
	seta (best, 255);
	seta (g, 0);
	g[0][1] = g[0][1] = 1;
	push (2, 0, 1);
	for (int i = 3; i < n; i ++)
	{
		int x, y;
		scanf ("%d%d", &x, &y);
		x --;
		y --;
		push (i, x, y);
	}
	int res = -inf;
	forn (i, n)
		forn (j, n)
			if (i != j)
			{
				go (i, j);
				res = max (res, best[i][j][0] + best[i][j][1] + 2);
			}
	cout << res;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
	int tt;            
	scanf ("%d", &tt);
	forn (ii, tt)
	{
		printf ("Case #%d: ", ii+1);
		goggogogog ();
		printf ("\n");
	}
	return 0;
}
