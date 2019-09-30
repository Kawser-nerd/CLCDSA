#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;
typedef long long i64;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y) + MOD) % MOD)
#define DBG(...) (fprintf(stderr, "[line %d]: ", __LINE__), fprintf(stderr, __VA_ARGS__))
#define MAXN 1000020

i64 fact[1010101], rev[1010101];
i64 pat[1010101];

i64 modpow(i64 a, int p)
{
	if (p == 0) return 1;
	i64 tmp = modpow(a, p / 2);
	tmp = tmp * tmp % MOD;
	if (p % 2) tmp = tmp * a % MOD;
	return tmp;
}

int sgn(int a)
{
	return a % 2 == 0 ? 1 : -1;
}

i64 C(int a, int b)
{
	return fact[a] * rev[b] % MOD * rev[a - b] % MOD;
}

void precalc()
{
	fact[0] = rev[0] = 1;
	for (int i = 1; i <= MAXN; ++i) {
		fact[i] = (fact[i - 1] * i) % MOD;
		rev[i] = (rev[i - 1] * modpow(i, MOD - 2)) % MOD;
	}
	
	for (int i = 0; i <= MAXN; ++i) pat[i] = fact[i] * fact[i] % MOD;
}

i64 solve(int N, int X)
{
	i64 ret = 0;
	if (X == 0) return pat[N];
	
	for (int i = X; i <= N; ++i) {
		ADD(ret, sgn(i - X) * (pat[N - i] * C(N, i) % MOD * C(N, i) % MOD * fact[i] % MOD * C(i - 1, X - 1) % MOD));
	}
	return ret;
}

int main()
{
	precalc();
	int n_testcase;
	scanf("%d", &n_testcase);
	
	for (int testcase_id = 0; testcase_id++ < n_testcase; ) {
		// input and solve the problem
		int N, X;
		scanf("%d%d", &N, &X);
		
		printf("Case #%d: %lld\n", testcase_id, solve(N, X));
		// print answer here
	}
	return 0;
}

