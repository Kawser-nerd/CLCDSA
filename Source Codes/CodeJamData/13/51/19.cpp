/*
    Author: Nikolay Kuznetsov
    Dedicated to my Love, Kristina Dmitrashko
*/
#ifdef NALP_PROJECT
#pragma hdrstop
#else
#define _SECURE_SCL 0
#endif

#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

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

int64 a[MAXN], n;

int64 calc(int64 minv, vector<int64> &p) {
	p.clear();
	int64 sum = 0;
	forn(i, 37)
		if (a[i] <= minv) {
			p.pb(minv - a[i]);
			sum += p.back();
			if (sum > n) break;
		}

	return sum;
}

int64 calcMax() {
	vector<int64> p;
	int64 l = 0, r = INF64;
	while (r - l > 1) {
		int64 mid = (l + r) >> 1;
		if (calc(mid, p) > n)
			r = mid;
		else
			l = mid;
	}

	int64 ans = 0;
	for(int64 mid = l; mid <= r; mid++)
		if (calc(mid, p) <= n)
			ans = mid;

	return ans;
}

void solve(bool skip) {
	n = nextInt64();
	int m = nextInt();
	memset(a, 0, sizeof a);
	forn(i, m)
		a[i] = nextInt64();

	long double ans = 0;
	for(int64 minv = max(0LL, calcMax() - 1000); ; minv++) {
		vector<int64> p;
		int64 sum = calc(minv, p);
		if (sum > n) break;

		int64 lost = 0;
		sort(all(p));
		forn(i, p.size()) {
			int64 pay = sum + i;
			if (pay > n) break;
			ans = max(ans, ((long double)36)*(sum - lost)/(int(p.size() - i)) - pay);
			lost += p[i];
		}

		if (sum > n) break;
	}

	cout.precision(15);
	cout << fixed << ans << endl;
}

int main(int argc, char * argv[]) {
#ifdef NALP_PROJECT
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#else
#endif

	int L = 1, R = INF;
	if (argc >= 3) {
		L = atoi(argv[1]);
		R = atoi(argv[2]);
	}

	srand((unsigned int)time(0));
	int tests = nextInt();
	forn(test, tests) {
		time_t start = clock();
		cerr << "Case #" << test + 1 << endl;
		cout << "Case #" << test + 1 << ": ";
		solve(test < L-1 || test > R-1);
		cerr << "time is " << (0.0 + clock() - start) / CLOCKS_PER_SEC << endl;
	}

	return 0;
}
