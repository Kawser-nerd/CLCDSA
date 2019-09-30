#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

static const ll mod = 1000000007;

ll modpow(ll a, ll b) {
	if (b == 0) return 1;
	ll res = modpow(a, b / 2);
	res = res * res % mod;
	if (b & 1) res = res * a % mod;
	return res;
}

ll modinv(ll a) {
	return modpow(a, mod-2);
}

ll solve() {
	ll N, X;
	cin >> N >> X;
	vector<ll> dp(N+1);
	dp[0] = 1;
	ll a = 0;
	rep(i,1,N+1) {
		if (i >= 2) a += dp[i-2];
		a = a * (i-1) % mod * (i-1) % mod;
		dp[i] = i * a % mod;
	}
	ll tot = 0;
	ll ans = 1;
	rep(i,0,N+1) {
		if (i >= X)
			tot += ans * dp[N-i] % mod;
		ans = ans * (N-i) % mod;
		ans = ans * modinv(i+1) % mod;
		ans = ans * (N-i) % mod;
	}
	return tot % mod;
}

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	rep(i,0,N) {
		cout << "Case #" << i + 1 << ": ";
		cout << solve() << endl;
	}
}
