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
#include <complex>

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

int n, a[110000], h[110000], b[110000];
bool ans;

void read() {
	scanf("%d", &n);
	forn(i, n - 1) {
		scanf("%d", &a[i]);
		a[i]--;
	}
}

void rec(int l, int r, int dep) {
	if (l == r)
		return;

	int p = -1;
	for (int i = l; i < r; i++)
		if (a[i] == r) {
			p = i;
			break;
		}

	if (p == -1) {
		ans = false;
		return;
	}

	h[p] = h[r] - dep * (r - p);

	rec(l, p, dep + 1);
	rec(p + 1, r, dep + 1);
}

void build() {
	forn(i, n - 1) {
		for (int j = i + 1; j < n; j++) {
			bool bad = false;
			for (int t = i + 1; t < n; t++) {
				double hh = h[i] + double(t - i) / double(j - i) * (h[j] - h[i]);
				if (t == j)
					continue;
				if (h[t] > hh) {
					bad = true;
					break;
				}
			}

			if (!bad)
				b[i] = j;
		}
	}
}

void solve() {
	h[n - 1] = INF;
	ans = true;
	rec(0, n - 1, 1);


	if (!ans)
		puts("Impossible");
	else {
		build();
		forn(i, n - 1)
			if (a[i] != b[i])
				throw;
		forn(i, n)
			printf("%d ", h[i]);
		puts("");
	}
}

void gen() {
	n = 2000;
	forn(i, n - 1)
		a[i] = i + 1;
}

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
/*
	gen();
	solve();
*/
#endif
	
	int tt;
	cin >> tt;
	forn(ii, tt) {
		cerr << ii << "/" << tt << endl;
		read();
		printf("Case #%d: ", ii + 1);
		solve();
	}
	
	return 0;
}