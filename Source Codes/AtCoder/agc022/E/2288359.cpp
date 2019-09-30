#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1e15;
const double eps = 1e-6;
const ll MOD = 1000000007;

int main() {
	string s;
	cin >> s;
	vector<ll> dp(10);
	vector<ll> ndp(10);
	const ll z = 0, zz = 1, zo = 2, o = 3, oz = 4, ozz = 5, ok = 6;
	if (s[0] == '1')
		dp[o]++;
	else if (s[0] == '0')
		dp[z]++;
	else if (s[0] == '?') {
		dp[o]++; dp[z]++;
	}
	for (int i = 1;i < s.size();i++) {
		ndp = vector<ll>(10);
		if (s[i] == '1') {
			ndp[z]   = dp[zz];
			ndp[zz]  = 0;
			ndp[zo]  = dp[z];
			ndp[o]   = dp[oz] + dp[zo];
			ndp[oz]  = dp[ozz];
			ndp[ozz] = 0;
			ndp[ok]  = dp[ok] + dp[o];
		}
		else if (s[i] == '0') {
			ndp[z]   = dp[zz] + dp[zo];
			ndp[zz]  = dp[z];
			ndp[zo]  = 0;
			ndp[o]   = 0;
			ndp[oz]  = dp[o] + dp[ozz];
			ndp[ozz] = dp[oz];
			ndp[ok]  = dp[ok];
		}
		else {
			ndp[z]  = dp[zz];
			ndp[zz] = 0;
			ndp[zo] = dp[z];
			ndp[o]  = dp[oz] + dp[zo];
			ndp[oz] = dp[ozz];
			ndp[ozz]= 0;
			ndp[ok] = dp[ok] + dp[o];

			ndp[z]  += dp[zz] + dp[zo];
			ndp[zz] += dp[z];
			ndp[zo] += 0;
			ndp[o]  += 0;
			ndp[oz] += dp[o] + dp[ozz];
			ndp[ozz]+= dp[oz];
			ndp[ok] += dp[ok];

		}
		dp = ndp;
		for (int i = 0;i < dp.size();i++)
			dp[i] %= MOD;
	}
	ll ans = (dp[o] + dp[ok]) % MOD;
	cout << ans << endl;
	return 0;
}