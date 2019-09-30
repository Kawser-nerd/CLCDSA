#include<iostream>
#include<map>
#include<vector>
using namespace std;

//???? O(n)??????????? O(1)

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// ??????????
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// ??????
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

map<int, int>prime_factor(int n) {
	map<int, int>res;
	for (int i = 2; i*i <= n; i++) {
		while (n%i == 0) {
			res[i]++;
			n /= i;
		}
	}
	if (n != 1)res[n]++;//n???
	return res;
}


int main() {
	// ???
	COMinit();
	int n, m;
	cin >> n >> m;
	map<int, int>mp = prime_factor(m);
	long long ans = 1;
    long long d = 1;
	for (int i = 2; i*i <= m; i++) {
		if (mp[i] > 0) {
			//i????
			ans *= COM(n + mp[i] - 1, mp[i]);
			ans %= MOD;
            for (int j = 0; j < mp[i]; j++) {
                d *= i;
            }
			//n/i????
			if ((m / d)*(m / d) > m  ) {
				ans *= COM(n + mp[m / d] - 1, mp[m / d]);
				ans %= MOD;
			}
		}
	}
	if (mp[m] == 1)ans = n;
	cout << ans << endl;
}