#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0

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

int m, v;
double z2[30][30][30], z[30];

double rec(int a);

double rec2(int a, int cur, int r) {
	if (z2[a][cur][r] > -EPS)
		return z2[a][cur][r];
	
	double res = rec(a - cur * ((1 << r) - 1));
	if (cur * (1 << r) <= m)
		res = max(res, 0.5 * rec2(a, cur, r + 1) + 0.5 * rec(a + cur));

	return z2[a][cur][r] = res;
}

double rec(int a) {
	if (a <= 0)
		return 0;
	if (a >= v)
		return 1;
	if (z[a] > -EPS)
		return z[a];

	double res = 0;
	for (int i = 1; i <= min(a, m); i++)
		res = max(res, rec2(a - i, i, 0));

	return res;
}

void solve() {
	int a;
	cin >> a >> m >> v;

	forn(i, 30)
		z[i] = 0;
	forn(i, 30)
		forn(j, 30)
			forn(t, 30)
				z2[i][j][t] = 0;

	forn(iter, 10000) {
		for (int tot = v - 1; tot > 0; tot--)
			for (int a = 0; a < tot; a++) {
				int cur = tot - a;
				for (int r = 5; r >= 0; r--) {
					if (r && a + cur > cur * ((1 << r) - 1)) {
						double x = 0;
						int na = a + cur - cur * ((1 << r) - 1);
						for (int i = 1; i <= na; i++)
							x = max(x, z2[na - i][i][0]);
						z2[a][cur][r] = max(z2[a][cur][r], x);
					}
					if (cur * (1 << r) <= m) {
						double val = 0.5 * z2[a][cur][r + 1] + 0.5 * (a + 2 * cur >= v ? 1 : 0);
						if (a + 2 * cur < v) {
							double x = 0;
							int na = a + 2 * cur;
							for (int i = 1; i <= na; i++)
								x = max(x, z2[na - i][i][0]);
							val += 0.5 * x;
						}
						z2[a][cur][r] = max(z2[a][cur][r], val);
					}
				}
			}
	}
	/*
	cout << z2[1][1][0] << endl;
	cout << z2[0][1][0] << endl;
	*/
//	double res = rec(a);
	double res = 0;
	int nn;
	fore(i, 1, a + 1) {
		if (res <= z2[a - i][i][0] + EPS) {
			res = z2[a - i][i][0];
			nn = i;
		}
//		printf("%.9lf ", z2[a - i][i][0]);
	}
	
	printf("%.9lf %d\n", res, nn);
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
		printf("Case #%d: ", ii + 1);

		solve();
	}

	cerr << clock() << endl;
	
	return 0;
}