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

int p, q, n, h[105], g[105], dp[105][2005][205];

void load() {
	cin >> p >> q >> n;

	for (int i = 0;i < n;i++) {
		cin >> h[i] >> g[i];
	}
}

int go (int pos, int have, int hp) {
	if (have > 2000) return 0;
	//cerr << pos << " " << have << " " << hp << endl;
	if (pos == n) {
		return 0;
	}

	int &res = dp[pos][have][hp];
	if (res != -1) return res;
	res = 0;

	if (hp <= q) {
		res = go (pos + 1, have + 1, h[pos + 1]);
	} else {
		res = go (pos, have + 1, hp - q);
	}
	if (have == 0) return res;

	if (hp <= p) {
		res = max (res, go (pos + 1, have - 1, h[pos + 1]) + g[pos]);
	} else {
		res = max (res, go (pos, have - 1, hp - p));
	}

	return res;
}

void solve(int test) {
	memset (dp, -1, sizeof (dp));
	printf ("Case #%d: %d\n", test, go (0, 1, h[0]));
}

int main() {
 	freopen ("a.in", "r", stdin);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		cerr << "process test: " << i << endl;
 		load();
 		solve(i);
 	}

 	return 0;
}