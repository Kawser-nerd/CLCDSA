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

const int MAXN = 2000100;

double d[MAXN];
string s;
int n;

double get(int mask) {
	if (mask + 1 == 1 << n) return 0;
	double &ans = d[mask];
	if (ans > -EPS) return ans;

	ans = 0;
	forn(i, n) {
		int x = i, cost = n;
		while (bit(mask, x)) {
			x = (x + 1) % n;
			cost--;
		}

		ans += (cost + get(mask | (1 << x))) / n;
	}

	return ans;
}

double stupid() {
	return 0;
}

void solve(bool skip) {
	if (true) {
		cin >> s;
		n = (int)s.size();
	} else {
		// Generate test
	}

	if (skip) {
		cout << "SKIPPED" << endl;
		return;
	}

	memset(d, 255, sizeof d);
	int mask = 0;
	forn(i, n)
		if (s[i] == 'X')
			mask ^= 1 << i;

	double ans = get(mask);
	cout.precision(15);
	cout << fixed << ans << endl;
	cerr << "\tclever answer is '" << ans << "'" << endl;
	if (false) {
		double stupidAnswer = stupid();
		cerr << "\tstupid answer is '" << stupidAnswer << "'" << endl;
		if (ans != stupidAnswer) {
			cerr << "\tanswers aren't equal!" << endl;
			throw;
		}
	}
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
