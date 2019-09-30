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

const int MAXN = 100;

int n, m, X, s[MAXN], t[MAXN], f[MAXN];
bool used[MAXN][MAXN];

bool check(int v, int st, int time) {
	memset(used, 0, sizeof used);
	forn(i, m) {
		int curV = s[i], curT = t[i];
		while (true) {
			used[curV][curT] = true;
			if (curV == f[i]) break;
			curV = (curV + 1) % n;
			curT++;
		}
	}

	forn(i, time + 1) {
		if (used[v][st])
			return false;

		v = (v - 1 + n) % n;
		st++;
	}

	return true;
}

int stupid() {
	return 0;
}

void solve() {
	bool GENERATE_TEST = false;
	if (!GENERATE_TEST) {
		m = nextInt();
		X = nextInt() * 2;
		n = nextInt() * 2;
		forn(i, m) {
			s[i] = 2 * (nextInt() - 1);
			f[i] = 2 * (nextInt() - 1);
			t[i] = 2 * nextInt();
		}
		// Read test
	} else {
		// Generate test
	}

	int ans = 0;
	forn(v, n)
		forn(st, X)
			for(int time = 1; time + st <= X; time++)
				if (st % 2 == 0 && v % 2 == 0 && time % 2 == 0 && check(v, st, time)) 
					ans = max(ans, time / 2);
	
	cout << ans << endl;

	cerr << "\tclever answer is '" << ans << "'" << endl;
	if (false) {
		int stupidAnswer = stupid();
		cerr << "\tstupid answer is '" << stupidAnswer << "'" << endl;
		if (ans != stupidAnswer) {
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
