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
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n;
int64 x[30], F, l, r, res;
vector < pair <int64, int> > togo[30];

void go (int p, int mask, int64 used)
{
	if (mask == ((1 << n) - 1))
	{
		if (abs (x[p] - x[0]) + used <= F)
			res = max (res, used + abs (x[p] - x[0]));
		return;
	}
	int64 l = x[p];
	int64 r = x[p];
	forn (i, n)
		if (!(mask & (1 << i)))
		{
			l = min (l, x[i]);
			r = max (r, x[i]);
		}
	int64 d = min (r - x[p] + r - l + abs (l), x[p] - l + r - l + abs (r));
	if (used + d > F)
		return;
	forn (i, togo[p].size())
		if (!(mask & (1 << togo[p][i].sc)))
			go (togo[p][i].sc, mask | (1 << togo[p][i].sc), used + togo[p][i].fs);
}

void goggogogog ()
{
	cin >> n;
	forn (i, n)
		cin >> x[i];
	forn (i, n)
	{
		togo[i].clear ();
		forn (j, n)
			if (i != j)
				togo[i].pb (mp (abs (x[j] - x[i]), j));
		sort (all (togo[i]));
		reverse (all (togo[i]));
	}
	cin >> F;
	l = 0;
	r = 0;
	forn (i, n)
	{
		l = min (l, x[i]);
		r = max (r, x[i]);
	}
	res = (r - l) * 2;
	if (res > F)
	{
		cout << "NO SOLUTION";
		return;
	}
	go (0, 1, 0);
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
