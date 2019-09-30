#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct H {
	ll val;
	int M;
	int D;
	H(int M, int D) : val((360 - D) * (ll)M), M(M), D(D) {}
};
bool operator<(const H& a, const H& b) {
	return a.val < b.val;
}

typedef vector<pii> vpii;
template<class F, class T>
void rec(int from, int to, F f, vpii& ret, int& i, T& p, T q) {
	if (p == q) return;
	if (from == to) {
		ret.emplace_back(i, to);
		i = to; p = q;
	} else {
		int mid = (from + to) >> 1;
		rec(from, mid, f, ret, i, p, f(mid));
		rec(mid+1, to, f, ret, i, p, q);
	}
}
template<class F>
vpii constantIntervals(int from, int to, F f) {
	vpii ret;
	if (to <= from) return ret;
	int i = from; auto p = f(i);
	rec(from, to-1, f, ret, i, p, f(to-1));
	ret.emplace_back(i, to);
	return ret;
}

int solve() {
	int N;
	cin >> N;
	vector<H> hikers;
	rep(i,0,N) {
		int D, H, M;
		cin >> D >> H >> M;
		rep(i,0,H) {
			hikers.emplace_back(M+i, D);
		}
	}
	sort(all(hikers));

	if (sz(hikers) <= 1) return 0;

	int lo = 0, hi = sz(hikers);
	while (lo + 1 < hi) {
		int i = (lo + hi) / 2;
		ll val = hikers[i].val;
		ll r = 0;
		rep(j,0,i+1) {
			ll v = ((hikers[j].D + val / hikers[j].M) / 360) - 1;
			r += v;
		}
		if (r > sz(hikers)) hi = i;
		else lo = i;
	}

	vector<vi> changes(hi);
	rep(j,0,hi) {
		vpii intv = constantIntervals(j, hi, [&](int i){ return (int)((hikers[j].D + hikers[i].val / hikers[j].M) / 360) - 1; });
		trav(pa, intv) {
			changes[pa.first].push_back(j);
		}
	}

	int res = sz(hikers);
	vi vals(hi);
	int sum = 0;
	rep(i,0,hi) {
		// ignore i+1 hikers, overtake the rest
		ll val = hikers[i].val;
		trav(j, changes[i]) {
			if (j <= i) sum -= vals[j];
			vals[j] = (int)((hikers[j].D + val / hikers[j].M) / 360) - 1;
			if (j <= i) sum += vals[j];
		}

		int r = sz(hikers) - (i+1);
		sum += vals[i];
		r += sum;
		// rep(j,0,i+1) r += vals[j];
		res = min(res, r);
	}
	return res;
}

int main() {
	int N;
	cin.sync_with_stdio(false);
	cin >> N;
	rep(i,0,N) {
		printf("Case #%d: %d\n", i+1, solve());
	}
}
