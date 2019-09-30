#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <thread>
#include <mutex>
#include <iomanip>

using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int n_testcases;

i64 modpow(i64 a, int p = MOD - 2)
{
	if (p == 0) return 1;
	i64 ret = modpow(a, p / 2);
	ret = ret * ret % MOD;
	if (p % 2) ret = ret * a % MOD;
	return ret;
}

i64 fact[10101010], finv[10101010];
i64 inv[10101010];

i64 avoid(int n, int k)
{
	i64 ret = 0;
	if (k == 0) return 1;
	for (int c = 1; c <= k; ++c) {
		if (c % 2 == 0) {
			if (c == k) {
				ADD(ret, finv[k]);
			} else {
				ADD(ret, finv[c] * c % MOD * inv[c + 1] % MOD);
			}
		}
	}
//	ret = (MOD + 1 - ret) % MOD;
//	printf("%d %d: %lld\n", n, k, ret);
	return ret;
}

int main()
{
	finv[0] = fact[0] = 1;
	for (int i = 1; i <= 10000000; ++i) {
		fact[i] = fact[i - 1] * i % MOD;
		finv[i] = finv[i - 1] * (inv[i] = modpow(i)) % MOD;
	}
	
	scanf("%d", &n_testcases);
	
	for (int t = 0; t < n_testcases; ++t) {
		int N, K;
		scanf("%d%d", &N, &K);
		i64 ret = avoid(N, K - 1);
		ret *= avoid(N, N - K);
		ret %= MOD;
		ret = (MOD + 1 - ret) % MOD;
		printf("Case #%d: %lld\n", t + 1, ret);
	}
	
	return 0;
}
