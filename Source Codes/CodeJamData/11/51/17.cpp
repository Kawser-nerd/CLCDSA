#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:200000000")

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

struct pt {
	double x, y;

	pt() {}

	pt(double x, double y): x(x), y(y) {}
};

vector<pt> a, b, c;

double area(vector<pt> a) {
	a.pb(a[0]);
	double res = 0;
	forn(i, a.size() - 1)
		res += (a[i].x - a[i + 1].x) * (a[i].y + a[i + 1].y) / 2;
	return abs(res);
}

pt get(pt a, pt b, double x) {
	pt res;
	res.x = x;
	res.y = a.y + (x - a.x) * (b.y - a.y) / (b.x - a.x);
	return res;
}

double f(double x) {
	vector<pt> res;
	forn(i, c.size() - 1) {
		if (c[i].x <= x)
			res.pb(c[i]);
		if (c[i].x < x && x < c[i + 1].x || c[i].x > x && x > c[i + 1].x)
			res.pb(get(c[i], c[i + 1], x));
	}
	return area(res);
}

void solve() {
	int w, l, u, g;
	cin >> w >> l >> u >> g;

	a.resize(l);
	b.resize(u);
	forn(i, l)
		cin >> a[i].x >> a[i].y;
	forn(i, u)
		cin >> b[i].x >> b[i].y;

	c = a;
	reverse(all(b));
	c.insert(c.end(), all(b));
	c.pb(c[0]);

	double s = area(c);
	for (int i = 1; i < g; i++) {
		double l = 0;
		double r = w;

		forn(j, 80) {
			double m1 = l + (r - l) / 3;
			double m2 = r - (r - l) / 3;

			if (abs(f(m1) - s * i / g) < abs(f(m2) - s * i / g))
				r = m2;
			else
				l = m1;
		}

		printf("%.6lf\n", (l + r) / 2);
	}
}

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif	
	
	int tt;
	scanf("%d", &tt);
	forn(ii, tt) {
		cerr << ii << ' ' << clock() << endl;
		printf("Case #%d:\n", ii + 1);

		solve();
	}

	cerr << clock() << endl;
	
	return 0;
}