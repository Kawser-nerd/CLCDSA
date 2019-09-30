//I Guds namn
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

const ll MAXN = 100 * 1000 + 13, MOD = 1000 * 1000 * 1000 + 7;

ll fact[MAXN];

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, m; cin >> n >> m;
	if(abs(n - m) > 1)
	{
		cout << 0 << endl;
		return 0;
	}
	fact[1] = 1;
	for(ll i = 2;i < MAXN;i++)
		fact[i] = (i * fact[i - 1]) % MOD;
	ll ans = (fact[n] * fact[m]) % MOD;
	if(m == n)
		ans *= 2;
	ans %= MOD;
	cout << ans << endl;
	return 0;
}