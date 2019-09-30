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
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int n;
double x[40], y[40], r[40];
double a[40][40], b[40][40], c[40][40];

int main ()
{
	int tt;
	scanf ("%d", &tt);
	forn (ii, tt)
	{
		printf ("Case #%d: ", ii+1);
		scanf ("%d", &n);
		forn (i, n)
			scanf ("%lf%lf%lf", &x[i], &y[i], &r[i]);
		double maxr = 0;
		forn (i, n)
			maxr = max (maxr, r[i]);
		double res = 1e100;
		if (n >= 3)
		forn (i, n)
			forn (j, n)
			{
				double dx = x[j] - x[i];
				double dy = y[j] - y[i];
				double d = sqrt (dx * dx + dy * dy);
				dx /= d;
				dy /= d;
				double x2 = x[j] + dx * r[j];
				double y2 = y[j] + dy * r[j];
				double x1 = x[i] - dx * r[i];
				double y1 = y[i] - dy * r[i];
				double mx = (x1 + x2) / 2;
				double my = (y1 + y2) / 2;
				double mr = sqrt (sqr (x2 - x1) + sqr (y2 - y1)) / 2;
				res = min (res, max (mr, maxr));
			}
		else
		res = maxr;
		printf ("%.6lf\n", res);
	}
	return 0;
}
