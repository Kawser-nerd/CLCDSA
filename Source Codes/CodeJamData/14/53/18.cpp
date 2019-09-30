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

int op[5005], ids, who[5005], ev[5005], dp[1 << 15][16][20], n;

void load() {   	
	memset (op, -1, sizeof (op));
	ids = 1;
	scanf ("%d\n", &n);
	for (int i = 0;i < n;i++) {
		char c;
		int id;
		scanf ("%c %d\n", &c, &id);
		if (id > 0 && op[id] == -1) {
			op[id] = ids++;
		}
		if (c == 'E') ev[i] = 0;
		else ev[i] = 1;
		who[i] = id;
	}
}

int go (int mask, int pos, int b) {
	//cerr << mask << " " << pos << " " << b << endl;
	if (pos == n) {
		return b + __builtin_popcount (mask);
	}

	int &res = dp[mask][pos][b];
	if (res != -1) return res;
	res = 1 << 30;

	if (who[pos] > 0) {
		int t = op[who[pos]] - 1;
		if (ev[pos] == 0 && has (mask, t)) return res;
		if (ev[pos] == 1 && !has (mask, t)) return res;

		if (ev[pos] == 0) {
			res = go (mask | (1 << t), pos + 1, b);
		} else {
			res = go (mask ^ (1 << t), pos + 1, b);
		}
		return res;
	}

	if (ev[pos] == 0) {
		res = go (mask, pos + 1, b + 1);
	} else {
		res = go (mask, pos + 1, max (b - 1, 0));
	}

	for (int i = 0;i < ids - 1;i++) {
		if (ev[pos] == 0) {
			if (!has (mask, i)) {
				res = min (res, go (mask | (1 << i), pos + 1, b));
			}
		} else {
			if (has (mask, i)) {
				res = min (res, go (mask ^ (1 << i), pos + 1, b));
			}
		}
	}
	return res;
}

void solve(int test) {
	memset (dp, -1, sizeof (dp));

	int ans = 1 << 30;
	for (int i = 0;i < (1 << (ids - 1));i++) {
		ans = min (ans, go (i, 0, 0));
	}

	printf ("Case #%d: ", test);
	if (ans < 1000) {
		cout << ans << endl;
	} else {
		puts ("CRIME TIME");
	}
}

int main() {
 	freopen ("a.in", "r", stdin);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		load();
 		solve(i);
 	}

 	return 0;
}
