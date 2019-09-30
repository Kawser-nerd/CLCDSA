#include<stdio.h>
#define MOD 1000000007
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
ll dp[1001][1001];
ll fact[1001];
ll ppow(ll a) {
	ll b=MOD-2;
	ll res = 1;
	while (b) {
		if (b & 1)res = (res*a) % MOD;
		a = (a*a) % MOD;
		b >>= 1;
	}
	return res;
}
ll comb(ll a, ll b) {
	return (((fact[a] * ppow(fact[a - b])) % MOD)*ppow(fact[b])) % MOD;
}
int main() {
	fact[0] = 1;
	int n, a, b, c, d; scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	for (int i = 1; i <= n; i++)fact[i] = (fact[i - 1] * i) % MOD;
	rep(i, n)dp[i][0] = 1;
	for (int i = a - 1; i < b; i++) {
		for (int j = 0; j <= n; j++) {
			if (j)(dp[i + 1][j] += dp[i][j]) %= MOD;
			if (j - c*(i + 1) < 0)continue;
			ll y = 1, t = n - j;
			rep(p, c - 1) {
				(y *= comb(t + i + 1, t)) %= MOD;
				t += i + 1;
			}
			for (int k = c; j - k*(i + 1) >= 0 && k <= d; k++) {
				(y *= comb(t + i + 1, t)) %= MOD;
				ll o = y;
				(o *= ppow(fact[k])) %= MOD;
				(dp[i + 1][j] += dp[i][j - k*(i + 1)] * o) %= MOD;
				t += i + 1;
			}
		}
	}
	printf("%lld\n",dp[b][n]);
}