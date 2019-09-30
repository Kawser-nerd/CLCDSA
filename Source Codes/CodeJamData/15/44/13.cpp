#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll mod = 1000000007;

void add(ll& a, ll v) { a = (a + v) % mod; }

int H, W;
ll count(int bits) {
#define ADD(where, val) do { \
	if (where == H) add(dp[H], val); \
	if (where + 2 <= H) add(dp[where+2], val); \
} while (0)
	vector<ll> dp(H+1);
	dp[0] = 1;
	dp[2] = 1;
	rep(i,0,H+1) {
		ll v = dp[i];
		ADD(i+1, v); // 2 line
		if (bits & 1) ADD(i+2, v * 3);
		if (bits & 2) ADD(i+2, v * 6);
		if (bits & 4) ADD(i+3, v * 4);
	}
	return dp[H];
}

ll solve() {
	cin >> H >> W;
	map<int, ll> stuff;
	rep(i,0,W) {
		int bits = 0;
		if (i % 3 == 0 && W % 3 == 0)
			bits |= 1;
		if (i % 6 == 0 && W % 6 == 0)
			bits |= 2;
		if (i % 4 == 0 && W % 4 == 0)
			bits |= 4;
		stuff[bits]++;
	}
	ll res = 0;
	trav(pa, stuff) {
		int bits = pa.first;
		res += count(bits) * pa.second % mod;
	}
	res %= mod;
	while (res % W) res += mod;
	res /= W;
	return res % mod;
}

int main() {
	int N;
	cin.sync_with_stdio(false);
	cin >> N;
	rep(i,0,N) {
		printf("Case #%d: %Ld\n", i+1, solve());
	}
}
