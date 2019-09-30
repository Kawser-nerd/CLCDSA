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

char buf[5], tp[2010];
int n, d[2010];
vector<int> g[2010];
int was[2010], it, used[2010], mt[2010];

int dfs(int x) {
	if (x == -1) return 1;
	if (used[x] == it) return 0;
	used[x] = it;

	forn(j, g[x].size()) {
		int y = g[x][j];
		int z = mt[y];
		mt[y] = x;
		if (dfs(z)) return 1;
		mt[y] = z;
	}

	return 0;
}

void solve() {
	scanf("%d", &n);
	// printf("==========\n%d\n", n);
	forn(i, n) {
		scanf("%s %d", buf, &d[i]);
		// printf("%s %d\n", buf, d[i]);
		tp[i] = buf[0];
		g[i].clear();
	}

	forn(i, n)
		if (tp[i] == 'E') {
			it++;
			for (int j = i + 1; j < n; j++) {
				if (tp[j] == 'L') {
					if (was[d[j]] != it || d[j] == 0)
						if (d[i] == 0 || d[i] == d[j] || d[j] == 0)
							g[i].pb(j);
					was[d[j]] = it;
				}
				if (d[j] == d[i] && d[i] != 0) break;
			}
		}

	it++;
	vector<int> start;
	forn(i, n)
		if (tp[i] == 'L') {
			if (was[d[i]] != it || d[i] == 0)
				start.pb(i);
			was[d[i]] = it;
		}

	int n2 = n;
	forn(i, start.size()) {
		g[n2].clear();
		forn(j, start.size())
			g[n2].pb(start[j]);
		tp[n2] = 'E';
		d[n2] = 0;
		n2++;
	}

	/*forn(i, n) {
		printf("%d:", i);
		forn(j, g[i].size()) printf(" %d", g[i][j]);
		printf("\n");
	}*/
	memset(mt, 0xff, sizeof(mt));
	int res = 0;
	forn(i, n2) {
		if (tp[i] == 'L') continue;
		it++;
		int z = dfs(i);
		if (i < n) res += z;
	}

	bool ok = true;
	forn(i, n)
		if (mt[i] != -1)
			mt[ mt[i] ] = i;

	forn(i, n)
		if (mt[i] == -1 && d[i] != 0) {
			if (tp[i] == 'E') {
				for (int j = i + 1; j < n; j++)
					if (tp[j] == 'E' && d[j] == d[i]) {
						ok = false;
						break;
					}
			} else {
				forn(j, i)
					if (tp[j] == 'L' && d[j] == d[i]) {
						ok = false;
						break;
					}
			}
		}

	if (!ok) {
		printf("CRIME TIME\n");
		return;
	}

	int ans = -res;
	forn(i, n) ans += tp[i] == 'E';

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
