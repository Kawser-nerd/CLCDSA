#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime> //clock()
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>

using namespace std;

#pragma comment(linker, "/STACK:33554432")

#ifdef __GNUC__
typedef long long int64;
#else //MS Visual Studio
typedef __int64 int64;
#endif

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define it iterator
#define last(a) a.size() - 1
#define all(a) a.begin(), a.end()

const long double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const long double PI = 2 * acos(.0);
const int NC = 10000000;

inline int64 rand64() {
	int64 res = ((int64)rand() << 48LL) + ((int64)rand() << 32LL) + ((int64)rand() << 16LL) 
		+ ((int64)rand() << 0LL);
	if (res < 0)
		res = -res;
	return res;
}

inline long double random(long double a) {
	int64 ret = rand64();
	long double ro = a * 1E9;
	int64 r64 = (int64)ro;
	ret %= r64;
	long double res = (long double)1.0 * ret / 1E9;
	return res;
}

long double f, R, t, r, g, rn;

long double dist0(long double x, long double y) {
	return sqrt((long double)(x - 0) * (x - 0) + (y - 0) * (y - 0));
}

long double dist(long double x, long double y, long double x2, long double y2) {
	return sqrt((long double)(x - x2) * (x - x2) + (y - y2) * (y - y2));
}

bool in(long double x, long double y) {
	return dist0(x, y) <= R - t - f;
}

bool onseg(long double xa, long double ya, long double xb, long double yb, long double xm, long double ym) {
	return abs(dist(xa, ya, xb, yb) - dist(xa, ya, xm, ym) - dist(xb, yb, xm, ym)) < EPS;
}

pair<long double, long double> inter(long double xa, long double ya, long double xb, long double yb) {
	vector<pair<long double, long double> > v;
	if (abs(xa - xb) < EPS) {
		v.pb(mp(xa, sqrt(rn * rn - xa * xa)));
		v.pb(mp(xa, -sqrt(rn * rn - xa * xa)));
	}
	else {
		v.pb(mp(sqrt(rn * rn - ya * ya), ya));
		v.pb(mp(-sqrt(rn * rn - ya * ya), ya));
	}

	forn(i, v.size())
		if (onseg(xa, ya, xb, yb, v[i].fs, v[i].sc))
			return v[i];

	return mp(-1, -1);
}

long double secu(pair<long double, long double> a) {
	return atan2(a.sc, a.fs) * rn * rn - a.fs * a.sc;
}

long double str(pair<long double, long double> a, pair<long double, long double> b) {
	if (a.fs > b.fs)
		swap(a, b);

	return (secu(a) - secu(b)) * 0.5;
}

long double s(int a, int b) {
	long double lx = (2 * r + g) * a + r + f;
	long double ly = (2 * r + g) * b + r + f;
	long double rx = (2 * r + g) * a + r + g - f;
	long double ry = (2 * r + g) * b + r + g - f;
	if (lx >= rx || ly >= ry)
		return 0;

	if (dist0(lx, ly) > R - t - f && dist0(rx, ry) > R - t - f 
		&& dist0(lx, ry) > R - t - f && dist0(rx, ly) > R - t - f)
		return 0;
	if (dist0(lx, ly) <= R - t - f && dist0(rx, ry) <= R - t - f 
		&& dist0(lx, ry) <= R - t - f && dist0(rx, ly) <= R - t - f)
		return (rx - lx) * (ry - ly);

//	return PI * (R - t - f) * (R - t - f) - PI * (lx * lx + ly * ly);

	vector<pair<long double, long double> > v;
	if (in(lx, ly) != in(lx, ry))
		v.pb(inter(lx, ly, lx, ry));
	if (in(lx, ly) != in(rx, ly))
		v.pb(inter(lx, ly, rx, ly));
	if (in(rx, ry) != in(lx, ry))
		v.pb(inter(rx, ry, lx, ry));
	if (in(rx, ry) != in(rx, ly))
		v.pb(inter(rx, ry, rx, ly));

	long double sh = str(v[0], v[1]);
	sh -= abs(v[0].fs - v[1].fs) * ly;

	long double res = (min(v[0].fs, v[1].fs) - lx) * (ry - ly) + sh;

	return res;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	srand((unsigned int)time(0));

	int tk;
	scanf("%d", &tk);
	forn(tt, tk) {
		cerr << tt << endl;
		cin >> f >> R >> t >> r >> g;
		rn = R - t - f;

		long double ans = 0;
		for (int i = 0; i <= 1100; i++)
			for (int j = 0; j <= 1100; j++)
				ans += s(i, j);
		ans *= 4.0;


/*
		int k = 0;
		forn(i, NC) {
			long double rc = random(R);
			if (rc > R - t - f) {
				k++;
				continue;
			}
			long double ac = random(2 * PI);

			long double x = abs(rc * cos(ac));
			long double y = abs(rc * sin(ac));

			x = x - floor(x / (2 * r + g)) * (2 * r + g);
			y = y - floor(y / (2 * r + g)) * (2 * r + g);
			if (x < r + f || y < r + f || x > r + g - f || y > r + g - f)
				k++;
		}

		long double ans = (long double)1.0 * k / NC;
*/

		ans /= PI * R * R;

		if (ans > 1)
			ans = 1;
		if (ans < 0)
			ans = 0;

		ans = 1.0 - ans;

		if (R - t - f < EPS)
			ans = 1.0;

		printf("Case #%d: %.6lf\n", tt + 1, ans);
	}
	
	return 0;
}