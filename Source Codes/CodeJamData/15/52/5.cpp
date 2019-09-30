#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int solve() {
	int N, K;
	cin >> N >> K;
	vi v(N-K+1);
	rep(i,0,N-K+1)
		cin >> v[i];
	vi lows(K), highs(K), cur(K);
	rep(i,K,N) {
		int ri = i % K;
		cur[ri] += v[i-K+1] - v[i-K];
		highs[ri] = max(highs[ri], cur[ri]);
		lows[ri] = min(lows[ri], cur[ri]);
	}
	ll sum = v[0];

	rep(i,0,K) {
		int add = -lows[i];
		sum -= add;
		highs[i] += add;
		lows[i] = 0;
	}
	sort(all(highs));
	int res = highs.back();

	ll slack = 0;
	rep(i,0,K)
		slack += highs.back() - highs[i];

	sum %= K;
	if (sum < 0) sum += K;

	if (sum > slack)
		++res;

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
