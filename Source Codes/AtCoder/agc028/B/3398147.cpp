#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define FOR(i, a, b) for(decltype(b) i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

#ifdef INPUT
#include <sstream>
stringstream input(R"(
10
1 2 4 8 16 32 64 128 256 512
)");
#define cin input
#endif

ll inv_mod( ll a, ll m )
{
  ll b, x, u, q, abs_m, tmp; 

  abs_m = ( m < 0 ) ? -m : m;
  b = m; x = 1; u = 0; 
  while ( b > 0 ) {
    q = a / b; 
    tmp = u; u = x - q * u; x = tmp;
    tmp = b; b = a - q * b; a = tmp;
  }

  return ( x < 0 ) ? abs_m + x : x;
}

// ?? m ????????????: fm = m! 2 (n - m - 2)! n! / (n - m - 2)! / (m + 2)! = n! m! 2 / (m + 2)! = 2 n! / (m + 1) / (m + 2)
// ?? m ???????????: gm = m! 1 (n - m - 1)! n! / (n - m - 1)! / (m + 1)! = n! m! 1 / (m + 1)! = n! / (m + 1)
// ?? n ??????????: n!

int main()
{
	int n;
	cin >> n;

	const ll mod = 1000000007ull;

    vector<ll> frac(n + 1);
    frac[0] = 1;
    REP (i, n)
        frac[i + 1] = frac[i] * (i + 1) % mod;

	vector<ll> inv(n + 1);
    REP (i, n)
        inv[i + 1] = inv_mod(i + 1, mod);

    vector<ll> fraci(n + 1);
    fraci[n] = inv_mod(frac[n], mod);
    for (auto i = n; i > 0; --i)
        fraci[i - 1] = fraci[i] * i % mod;
	
	vector<ll> sum(n - 1);
	REP (i, n - 2)
		sum[i + 1] = (sum[i] + 2 * frac[n] * inv[i + 2] % mod * inv[i + 3] % mod) % mod;

	ll c = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i != n)
			c += frac[n] * inv[i + 1];
		else
			c += frac[n];
		c %= mod;
	}

	ll r = 0;
	REP (i, n)
	{
		int a;
		cin >> a;
		r += a * c;
		r %= mod;

		c += mod * mod - frac[n] * inv[i + 2];
		c %= mod;
		c += frac[n] * inv[n - i];
		c %= mod;

		if ((i + 1) * 2 < n)
		{
			c += sum[n - i - 2] + mod - sum[i];
			c %= mod;
		}
		if ((i + 1) * 2 > n)
		{
			int j = n - i;
			if (j >= 2)
			{
				c += mod - sum[n - j] + sum[j - 2];
				c %= mod;
			}
		}
	}

	cout << r << endl;

	return 0;
}