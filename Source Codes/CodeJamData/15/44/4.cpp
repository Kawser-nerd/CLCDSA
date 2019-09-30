#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int T;
int R, C;

i64 dp2[120], dp3[120]; // next: type 2 / type 3

i64 modpow(i64 a, i64 p)
{
	if (p == 1) return a;
	i64 tmp = modpow(a, p / 2);
	tmp = (tmp * tmp) % MOD;
	if (p % 2 == 1) tmp = (tmp * a) % MOD;
	return tmp; 
}

i64 inv(i64 a)
{
	return modpow(a, MOD - 2);
}

i64 solve(int rot)
{
	dp3[0] = dp2[0] = 1;

	for (int i = 1; i <= R; ++i) {
		dp2[i] = 0;
		dp3[i] = 0;

		ADD(dp3[i], dp2[i - 1]);
		if (C % 3 == 0 && i >= 2 && rot % 3 == 0) ADD(dp3[i], dp2[i - 2] * 3);
		if (C % 4 == 0 && i >= 3 && rot % 4 == 0) ADD(dp3[i], dp2[i - 3] * 4);
		if (C % 6 == 0 && i >= 2 && rot % 6 == 0) ADD(dp3[i], dp2[i - 2] * 6);

		if (i >= 2) ADD(dp2[i], dp3[i - 2]);
	}

	return dp2[R] + dp3[R];
}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;){
		scanf("%d%d", &R, &C);

		i64 ret = 0;
		for (int i = 1; i <= C; ++i) ADD(ret, solve(i));

		ret = (ret * inv(C)) % MOD;

		printf("Case #%d: %lld\n", t, ret);
	}

	return 0;
}
