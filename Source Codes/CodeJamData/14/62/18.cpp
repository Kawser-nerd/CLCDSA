// GCJ
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <map>
#include <set>

using namespace std;

// Self Template Code BGEIN

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long int64;
typedef pair<int, int> pii;

int sgn(double x) { return (x > 1e-8) - (x < -1e-8); }
int count_bit(int x) { return x == 0? 0 : count_bit(x >> 1) + (x & 1); }

template<class T> inline void ckmin(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T &a, const T b) { if (b > a) a = b; }

// Self Template Code END

long long fac[13], ret;
int a[1 << 12], n, tn;

void input() {
	scanf ("%d", &n);
	tn = (1 << n);
	rep (i, tn) {
		scanf ("%d", &a[i]);
	}
}

bool match(int x, int y, int d) {
	return a[y] - a[x] == d;
}

void try_swap(int x, int y) {
	swap (a[x], a[y]);
}

void dfs(int d1, int d2) {
	if (d1 == n) {
		ret += fac[d2];
		return ;
	}
	int c = (1 << (d1 + 1)), d = (1 << d1);
	int p = 0;
	int t[2];
	for (int i = 0; i < tn; i += c) {
		if ((a[i] - 1) % c != 0 || a[i + d] - a[i] != d) {
			if (p <= 1) {
				t[p] = i;
			}
			p += 1;
			if (p > 2) return ;
		}
	}
	// printf ("dfs %d %d %d\n", d1, d2, p);
	if (p > 2) {
		return ;
	}
	if (p == 0) {
		dfs (d1 + 1, d2);
	}
	if (p == 1) {
		if (match(t[0] + d, t[0], d)) {
			swap (a[t[0]], a[t[0] + d]);
			dfs (d1 + 1, d2 + 1);
			swap (a[t[0]], a[t[0] + d]);
		}
	}
	if (p == 2) {
		if (match(t[0], t[1], d) && match(t[0] + d, t[1] + d, d)) {
			try_swap (t[1], t[0] + d);
			dfs (d1 + 1, d2 + 1);
			try_swap (t[1], t[0] + d);
		}
		if (match(t[1] + d, t[0] + d, d) && match(t[1], t[0], d)) {
			try_swap (t[0], t[1] + d);
			dfs (d1 + 1, d2 + 1);
			try_swap (t[0], t[1] + d);
		}
		if (match(t[0], t[1] + d, d) && match(t[1], t[0] + d, d)) {
			try_swap (t[1], t[0]);
			dfs (d1 + 1, d2 + 1);
			try_swap (t[1], t[0]);

			try_swap (t[1] + d, t[0] + d);
			dfs (d1 + 1, d2 + 1);
			try_swap (t[1] + d, t[0] + d);
		}
	}
} 

void solve() {
	ret = 0;
	dfs (0, 0);

	cout << ret << endl;
}

int main() {
	freopen ("B.out", "w", stdout);

	fac[0] = 1LL;
	repf (i, 1, 12) {
		fac[i] = fac[i - 1] * i;
	}

	repcase {
		fprintf(stderr, "solving case %d / %d...\n", Case, t + Case - 1);
		printf ("Case #%d: ", Case++);

		input();

		solve();
	}
	return 0;
}