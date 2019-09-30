#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 4010, mod = 1000000007, inv2 = mod + 1 >> 1, M = N * 50;
ll a[M], b[M], fac[N * 2], n, x, inv[N * 2], ans, num[N][N];
ll qow(ll a, ll b)
{
	ll ans = 1;
	for (; b; b >>= 1)
	{
		if (b & 1)
			ans = ans * a % mod;
		a = a * a % mod;
	}
	return ans;
}
ll f(ll i, ll j)
{
	return fac[i + j] * inv[i] % mod * inv[j] % mod;
}
ll& upd(ll &a, ll b)
{
	a = a + b < mod ? a + b : a + b - mod;
	return a;
}
int main()
{
	fac[0] = 1;
	for (ll i = 1; i < 8001; i++)
		fac[i] = fac[i - 1] * i % mod;
	inv[8000] = qow(fac[8000], mod - 2);
	for (ll i = 7999; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % mod;
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++)
	{
		scanf("%lld%lld", a + i, b + i);
		num[2000 - a[i]][2000 - b[i]]++;
	}
	for (ll i = 0; i < 4001; i++)
		for (ll j = 0; j < 4001; j++)
		{
			if (i > 0)
				upd(num[i][j], num[i - 1][j]);
			if (j > 0)
				upd(num[i][j], num[i][j - 1]);
		}
	for (ll i = 1; i <= n; i++)
	{
		upd(ans, num[a[i] + 2000][b[i] + 2000]);
		upd(ans, mod - f(a[i] * 2, b[i] * 2));
	}
	cout << ans * inv2 % mod;
} ./Main.cpp:4:49: warning: operator '>>' has lower precedence than '+'; '+' will be evaluated first [-Wshift-op-parentheses]
const ll N = 4010, mod = 1000000007, inv2 = mod + 1 >> 1, M = N * 50;
                                            ~~~~^~~ ~~
./Main.cpp:4:49: note: place parentheses around the '+' expression to silence this warning
const ll N = 4010, mod = 1000000007, inv2 = mod + 1 >> 1, M = N * 50;
                                                ^
                                            (      )
1 warning generated.