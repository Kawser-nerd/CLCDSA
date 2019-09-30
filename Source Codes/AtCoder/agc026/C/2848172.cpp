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
#include <cmath>

using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;

const ll INF = 1e15;
const ld eps = 1e-15;

int main() {
	ll N;
	cin >> N;
	string s;
	cin >> s;
	ll ans = 0;
	for (ll i = 0;i < 1LL << N;i++) {
		string target = "";
		ll A = 0;
		ll B = 0;
		for (ll k = 0;k < N;k++)
			if ((1LL << k) & i) {
				target.push_back(s[k]);
				A++;
			}
		for (ll k = N - 1;k >= 0;k--)
			if ((1LL << k) & ~i) {
				target.push_back(s[k]);
				B++;
			}
		vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
		dp[A][B] = 1;
		for (int k = 0;k < N;k++) {
			for (int a = max(A, k+B-N);a <= min(N, A+k);a++) {
				ll b = B + k - (a - A);
				if (b < B || b > N)
					continue;
				if (a < N && target[a] == s[N + k])
					dp[a + 1][b] += dp[a][b];
				if (N-b-1 >= 0 && target[N - b - 1] == s[N + k])
					dp[a][b + 1] += dp[a][b];
			}
		}
		ans += dp[N][N];
	}
	cout << ans << endl;
	return 0;
}