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

const int md = 1000002013;

int n, m, o[1010], e[1010], p[1010];

void add(int& x, ll y) {
	x = (y + x) % md;
}

ll cost(int a, int b) {
	ll len = b - a;
	a = n;
	b = n - len + 1;
	return (len * ll(a + b) / 2) % md;
}

pii st[20010];
int tos;

void solve() {
	scanf("%d %d", &n, &m);
	vector<pii> ev;
	int total = 0;
	forn(i, m) {
		scanf("%d %d %d", &o[i], &e[i], &p[i]);
		ev.pb(pii(e[i], p[i]));
		ev.pb(pii(o[i], -p[i]));
		add(total, cost(o[i], e[i]) * p[i]);
	}

	sort(ev.begin(), ev.end());

	tos = 0;
	int t2 = 0;
	forn(i, ev.size())
		if (ev[i].second < 0) {
			st[tos++] = ev[i];
		} else {
			int x = ev[i].second;
			while (x > 0) {
				int y = min(x, -st[tos-1].second);
				add(t2, cost(st[tos-1].first, ev[i].first) * y);
				x -= y;
				st[tos-1].second += y;
				if (st[tos-1].second == 0) tos--;
			}
		}

	total = (total - t2 + md) % md;

	printf("%d\n", total);
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