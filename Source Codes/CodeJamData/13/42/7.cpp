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

int n;
ll p;
ll total;

bool itm(ll res) {
	return total - res <= p;
}

bool win_if_bad(ll x) {
	ll lose = total - x - 1;
	ll win = x;
	ll res = 0;
	forn(i, n) {
		res *= 2;
		if (win == 0) res++;
		else {
			win--;
			/*if (win > lose) {
				win -= lose;
				win = win/2 + lose;
				lose = 0;
			} else {
				lose -= win;
				lose = lose/2 + win;
			}*/
			if (win & 1) {
				win >>= 1;
				lose = (lose >> 1) + 1;
			} else {
				lose >>= 1;
				win >>= 1;
			}
		}
	}
	return itm(res);
}

bool win_if_good(ll x) {
	ll lose = total - x - 1;
	ll win = x;
	ll res = 0;
	forn(i, n) {
		res *= 2;
		if (win == 0) res++;
		else {
			if (lose == 0) continue;
			lose--;
			res++;
			if (lose & 1) {
				lose >>= 1;
				win = (win >> 1) + 1;
			} else {
				lose >>= 1;
				win >>= 1;
			}
		}
	}
	return itm(res);
}

ll always() {
	ll l = 0, r = (1LL << n) - 1;
	while (r - l > 1) {
		ll m = (l + r) >> 1;
		if (win_if_bad(m)) l = m;
		else r = m;
	}
	if (win_if_bad(r)) return r;
	return l;
}

ll may() {
	ll l = 0, r = (1LL << n) - 1;
	while (r - l > 1) {
		ll m = (l + r) >> 1;
		if (win_if_good(m)) l = m;
		else r = m;
	}
	if (win_if_good(r)) return r;
	return l;
}

void solve() {
	cin >> n >> p;
	total = 1LL << n;
	cout << always() << " " << may() << endl;
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