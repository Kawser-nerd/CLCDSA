#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;

const int N = 1000005;

int fac[N], inv[N], f[N];

int inverse(int a) {
	return a == 1 ? 1 : (long long)(MOD - MOD / a) * inverse(MOD % a) % MOD;
}

int perm(int n, int m) {
	return (long long)fac[n] * inv[n - m] % MOD;
}

int main() {
	fac[0] = inv[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = (long long)fac[i - 1] * i % MOD;
		inv[i] = inverse(fac[i]);
	}
	f[0] = 1; f[1] = 0;
	for (int i = 2; i < N; ++i) {
		f[i] = ((long long)f[i - 1] * i % MOD * (i - 1) + (long long)f[i - 2] * perm(i - 1, 1) % MOD * perm(i, 2) % MOD) % MOD;
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, x;
		scanf("%d%d", &n, &x);
		int ans = 0;
		for (int i = x; i <= n; ++i) {
			(ans += (long long)perm(n, i) * perm(n, i) % MOD * inv[i] % MOD * f[n - i] % MOD) %= MOD;
		}
		static int id = 0;
		printf("Case #%d: %d\n", ++id, ans);
	}
	return 0;
}
