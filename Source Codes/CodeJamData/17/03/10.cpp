#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pct __builtin_popcount

#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (__typeof((c).begin()) i=((c).begin()); i!=((c).end()); i++)

set<PLL> A;

void add(ll x, ll y) {
	set<PLL>::iterator i = A.lower_bound(mp(x, 0LL));
	if (i == A.end() || i->fi != x) {
		A.insert(mp(x, y));
		return;
	}
	PLL w = *i;
	w.se += y;
	A.erase(i);
	A.insert(w);
}

int main() {
	int _;
	cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		ll n, k;
		cin >> n >> k;
		A.clear();
		A.insert(mp(n, 1LL));
		k--;
		while (k) {
			PLL x = *A.rbegin();
			A.erase(x);
			ll c = min(x.se, k);
			add((x.fi-1)/2, c);
			add(x.fi/2, c);
			x.se -= c;
			if (x.se) A.insert(x);
			k -= c;
		}
		ll w = A.rbegin()->fi;
		printf ("Case #%d: %lld %lld\n", __, w/2, (w-1)/2);
	}
	return 0;
}
