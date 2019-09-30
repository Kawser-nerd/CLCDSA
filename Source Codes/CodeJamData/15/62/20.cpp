#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

const int MOD = (int)1e9 + 7;
const int N = 1000000 + 10;

int n, x;
long long fact[N];
long long inv_fact[N];
long long inv[N];
long long f[N];
long long d[N];

long long binom(int n, int x)
{
	return fact[n] * inv_fact[x] % MOD * inv_fact[n - x] % MOD;
}

long long put3(int n, int x)
{
	return binom(n, x) * binom(n, x) % MOD * fact[x] % MOD;
}

void prepare()
{
	d[1] = 0;
	d[2] = 1;
	for(int i = 3; i < N; ++ i) {
		d[i] = (i - 1) * (d[i - 2] + d[i - 1]) % MOD;
	}
	long long ret = 1;
	for(int i = 1; i < N; ++ i) {
		ret = ret * i % MOD;
		f[i] = ret * d[i] % MOD;
	}
	f[0] = 1;

	inv[1] = 1;
	for(int i = 2; i < N; ++ i) {
		inv[i] = ((long long)(MOD - MOD / i) * inv[MOD % i]) % MOD;
		assert(inv[i] * i % MOD == 1);
	}

	fact[0] = 1;
	inv_fact[0] = 1;
	for(int i = 1; i < N; ++ i) {
		fact[i] = fact[i - 1] * i % MOD;
		inv_fact[i] = inv_fact[i - 1] * inv[i] % MOD;
	}
}

void solve()
{
	cin >> n;
	cin >> x;
	long long ans = 0;
	for(int i = x; i <= n; ++ i) {
		ans += put3(n, i) * f[n - i] % MOD;
	}
	cout << ans % MOD << endl;
}

int main()
{
	prepare();
	//freopen("B-small-attempt0.in", "r", stdin); freopen("B-small-attempt0.out", "w", stdout);
	//freopen("B-small-attempt1.in", "r", stdin); freopen("B-small-attempt1.out", "w", stdout);
	//freopen("B-small-attempt2.in", "r", stdin); freopen("B-small-attempt2.out", "w", stdout);
	freopen("B-large.in", "r", stdin); freopen("B-large.out", "w", stdout);
	int test_case;
	cin >> test_case;
	for(int i = 0; i < test_case; ++ i) {
		printf("Case #%d: ", i + 1);
		cerr << "now " << i << endl;
		solve();
	}
	return 0;
}
