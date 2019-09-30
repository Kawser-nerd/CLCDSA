#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> stuff;
vector<ll> res;

void rec(map<ll, ll> S) {
	while (S.size() != 1) {
		auto it = S.begin(), it2 = it; ++it2;
		ll v = it2->first - it->first;
		stuff.push_back(v);

		trav(pa, S) {
			if (pa.second) S[pa.first + v] -= pa.second;
		}
		for (auto it = S.begin(); it != S.end();) {
			if (it->second == 0) S.erase(it++);
			else ++it;
		}
	}
}

template<class F>
void each(vector<ll>& v, int i, ll sum, F f, set<pair<ll, int> >& avoid) {
	if (i == sz(v)) {
		f(sum);
		return;
	}

	pair<ll, int> avp(sum, i);
	if (avoid.count(avp))
		return;
	avoid.insert(avp);

	res.push_back(-v[i]);
	each(v, i+1, sum - v[i], f, avoid);
	res.pop_back();
	res.push_back(v[i]);
	each(v, i+1, sum + v[i], f, avoid);
	res.pop_back();
}

void signs(ll sumAll) {
	int N = sz(stuff);
	int half = N / 2;
	sort(all(stuff));
	reverse(all(stuff));
	vector<ll> halfv, halfv2;
	rep(i,0,N) {
		if (i >= half)
			halfv2.push_back(stuff[i]);
		else
			halfv.push_back(stuff[i]);
	}
	set<pair<ll, int> > A, B, C;
	set<ll> seen;
	each(halfv2, 0, 0, [&](ll x) {
		seen.insert(x);
	},A);
	try {
		each(halfv, 0, 0, [&](ll x) {
			if (seen.count(sumAll-x))
				throw sumAll-x;
		},B);
	} catch(ll wanted) {
		try {
			each(halfv2, 0, 0, [&](ll x) {
				if (x == wanted)
					throw 0;
			},C);
		} catch(int) {
			return;
		}
	}
	assert(0);
}

void solve() {
	int P;
	cin >> P;
	vector<ll> E(P), F(P);
	rep(i,0,P) cin >> E[i];
	rep(i,0,P) cin >> F[i];
	ll sumNeg = E[0];
	ll sumPos = E.back();
	ll zeroes2 = F[0];
	ll zeroes3 = F[0];
	int zeroes = 0;
	while (zeroes2 % 2 == 0) {
		++zeroes;
		zeroes2 /= 2;
	}
	trav(f, F) f /= zeroes3;
	map<ll, ll> S;
	rep(i,0,P)
		S[E[i]] = F[i];
	rec(S);
	signs(sumNeg + sumPos);

	rep(i,0,zeroes) res.push_back(0);
	sort(all(res));
	trav(x, res) printf(" %lld", x);

	puts("");
	stuff.clear();
	res.clear();
}

int main() {
	int N;
	cin.sync_with_stdio(false);
	cin >> N;
	rep(i,0,N) {
		printf("Case #%d:", i+1);
		solve();
	}
}
