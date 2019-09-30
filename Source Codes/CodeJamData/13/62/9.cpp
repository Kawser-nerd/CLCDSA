#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:500000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
#include <memory.h>

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define y1 YYY1
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> inline T Abs(T x) { return (x >= 0) ? x : -x; }
template<typename T> inline T sqr(T x) { return x * x; }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int bit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }

inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline int64 nextInt64() { int64 x; if (scanf("%I64d", &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 100100;

double a[MAXN];
int n;

int check(double gap, double len) {
	double l = -1E20, r = +1E20;
	for(int i = 0; i < n; i++) {
		double ll = a[i] - gap - len*i, rr = a[i] + gap - len*i;
		if (ll > r) return -1;
		if (rr < l) return +1;
		l = max(l, ll);
		r = min(r, rr);
	}

	return 0;
}

bool check(double x) {
	double l = 0, r = 1E8;
	forn(i, 100) {
		double mid = (l + r) / 2;
		int res = check(x, mid);
		if (res == 0) return true;
		if (res > 0) r = mid;
		if (res < 0) l = mid;
	}

	return check(x, (l + r) / 2) == 0;
}

bool check2(int v, double value, double x) {
	double l = -1E20, r = 1E20;
	forn(i, n) {
		double ll = a[i] - x, rr = a[i] + x;
		if (i < v) {
			l = max(l, (value - rr) / abs(i - v));
			r = min(r, (value - ll) / abs(i - v));
		}

		if (i > v) {
			l = max(l, (ll - value) / abs(i - v));
			r = min(r, (rr - value) / abs(i - v));
		}
	}

	return l <= r;
}

bool check2(double x) {
	forn(i, n) {
		if (check2(i, a[i] + x, x)) return true;
		if (check2(i, a[i] - x, x)) return true;
	}

	return false;
}

double stupid() {
	double l = 0, r = 1E10;
	forn(i, 120) {
		double mid = (l + r) / 2;
		if (check2(mid))
			r = mid;
		else
			l = mid;
	}

	double ans = (l + r) / 2;
	return ans;
}

void solve() {
	bool GENERATE_TEST = false;
	if (!GENERATE_TEST) {
		n = nextInt();
		forn(i, n)
			a[i] = nextInt();
	} else {
		n = 50000;
		forn(i, n)
			a[i] = rand();
		sort(a, a + n);
	}

	double l = 0, r = 1E10;
	forn(i, 120) {
		double mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}

	double ans = (l + r) / 2;

	cout.precision(10);
	cout << fixed << ans << endl;

	cerr << "\tclever answer is '" << ans << "'" << endl;
	if (n < 100) {
		double stupidAnswer = stupid();
		cerr << "\tstupid answer is '" << stupidAnswer << "'" << endl;
		if (abs(ans - stupidAnswer) > EPS) {
			cerr << "\tanswers aren't equal!" << endl;
			throw;
		}
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	srand((unsigned int)time(0));
	int tests = nextInt();
	forn(test, tests) {
		time_t start = clock();
		cerr << "Case #" << test + 1 << endl;
		cout << "Case #" << test + 1 << ": ";
		solve();
		cerr << "time is " << (0.0 + clock() - start) / CLOCKS_PER_SEC << endl;
	}

	return 0;
}
