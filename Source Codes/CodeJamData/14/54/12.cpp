#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <numeric>

using namespace std;

#define sqr(a) ((a)*(a))
#define two(a) (1 << (a))
#define has(mask, a) ((mask) & two(a) ? 1 : 0)

int n, dp[105][105][2], was[105], lca[105][105][105], wdp[105][105][2], c[105];

vector <int> g[105];

void load() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> c[i];
		g[i].clear();
	}

	for (int i = 0, a;i < n - 1;i++) {
		cin >> a;
		a--;
		g[i].push_back (a);
		g[a].push_back (i);
	}
}

bool golca (int v, int t, int s) {
	was[v] = 1;
	if (v == t) {
		for (int i = 0;i < n;i++) {
			if (was[i]) {
				lca[s][t][i] = 1;
			}
		}
		return true;	
	}

	for (int i = 0;i < (int)g[v].size();i++) {
		int u = g[v][i];
		if (was[u]) continue;

		if (golca (u, t, s)) return true;
	}
	was[v] = 0;
	return false;
}

void getLCA() {
	memset (lca, 0, sizeof (lca));

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			memset (was, 0, sizeof (was));
			golca (i, j, i);
		}
	}
}

bool wasIn (int x1, int y1, int v, int x2, int y2, int sw) {
	if (sw) swap (x1, x2);
	if (lca[x1][y1][v] || lca[x2][y2][v]) return true;
	return false;
}

bool valid (int x1, int y1, int v, int x2, int y2, int sw) {
	if (sw) swap (x1, x2);
	if (lca[x1][y1][v]) return false;
	if (lca[x2][y2][v] && lca[x2][y2][y1]) return false;
	return true;
}

bool canMove (int x1, int y1, int x2, int y2, int sw) {
	for (int i = 0;i < (int)g[y1].size();i++) {
		int v = g[y1][i];
		if (valid (x1, y1, v, x2, y2, sw)) return true;
	}
	return false;
}

int x1, x2;

int go (int y1, int y2, int sw) {
	/*cerr << y1 << " " << y2 << endl;
	if (y1 == 1 && y2 == 4 && sw == 1) {
		cerr << valid (x1, y1, 0, x2, y2, sw) << "!\n";
		cerr << lca[x1][y1][0] << " " << lca[x2][y2][0] << " " << lca[x2][y2][y1] << endl;
	}*/

	if (!canMove (x1, y1, x2, y2, sw) && !canMove (x2, y2, x1, y1, sw)) return 0;

	int &res = dp[y1][y2][sw];
	if (wdp[y1][y2][sw]) return res;
	wdp[y1][y2][sw] = 1;
	res = -((int)1e8);

	if (!canMove (x1, y1, x2, y2, sw)) return res = -go (y2, y1, 1 - sw);

	for (int i = 0;i < (int)g[y1].size();i++) {
		int v = g[y1][i];
		if (!valid (x1, y1, v, x2, y2, sw)) continue;

		int cc = wasIn (x1, y1, v, x2, y2, sw) ? 0 : c[v];
		res = max (res, cc - go (y2, v, 1 - sw));
	}
	return res;
}

void solve(int test) {
	getLCA();
	/*x1 = 7;
	x2 = 0;
	cerr << go (7, 0, 0) << endl;
	return;*/
	int ans = -((int)1e9);

	for (x1 = 0;x1 < n;x1++) {
		int cur = -(int)1e9;
		//cerr << x1 << ":\n";
		for (x2 = 0;x2 < n;x2++) {
			memset (wdp, 0, sizeof (wdp));
			cur = max (cur, (x1 == x2 ? 0 : c[x2]) - go (x1, x2, 0));
			//cerr << x2 << " " << (x1 == x2 ? 0 : c[x2]) - go (x1, x2, 0) <<endl;
		}
		ans = max (ans, c[x1] - cur);
	}
	printf ("Case #%d: %d\n", test, ans);
}

int main() {
 	freopen ("a.in", "r", stdin);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		cerr << i << endl;
 		load();
 		solve(i);
 	}

 	return 0;
}
