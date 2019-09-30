#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int n, x, c[4010];
vector<pii> g[4010];
bool used[4010];

int get(int i, int j, int w, int r) {
	int res = 0;
	if (w == 0) {
		int wasc = c[i];
		res = c[i];
		c[i] = 0;
		int best = 80000 * n;
		forn(w, g[i].size()) {
			int y = g[i][w].first;
			int r = g[i][w].second;
			if (!used[r]) {
				used[r] = true;
				int z = get(y, j, 1, 0);
				if (z < best) best = z;
				used[r] = false;
			}
		}
		if (best == 80000 * n) {
			if (r) best = 0;
			else best = get(i, j, 1, 1);
		}
		res -= best;

		c[i] = wasc;
	} else {
		int wasc = c[j];
		res = c[j];
		c[j] = 0;
		int best = 80000 * n;
		forn(w, g[j].size()) {
			int y = g[j][w].first;
			int r = g[j][w].second;
			if (!used[r]) {
				used[r] = true;
				int z = get(i, y, 0, 0);
				if (z < best) best = z;
				used[r] = false;
			}
		}
		if (best == 80000 * n) {
			if (r) best = 0;
			else best = get(i, j, 0, 1);
		}
		res -= best;

		c[j] = wasc;
	}

	// printf("get %d %d %d %d -> %d\n", i, j, w, r, res);
	return res;
}

void solve() {
	scanf("%d", &n);
	forn(i, n) scanf("%d", &c[i]), g[i].clear();
	forn(i, n-1) {
		scanf("%d", &x);
		x--;
		g[i].pb(pii(x, i));
		g[x].pb(pii(i, i));
	}

	int ans = -n * 80000;
	forn(i, n) {
		int cur = n * 80000;
		forn(j, n) {
			int z = get(i, j, 0, 0);
			// printf("get %d %d %d -> %d\n", i, j, 0, z);
			if (z < cur) cur = z;
		}
		if (cur > ans) ans = cur;
	}
		// get(0, 1, 0, 0);

	printf("%d\n", ans);
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int q = 1; q <= tc; q++) {
		printf("Case #%d: ", q);
		solve();
		fprintf(stderr, "Case %d done.\n", q);
	}
	return 0;
}
