#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int MOD = (int) 1e9 + 7;

void sadd(int &a, int b)
{
	a += b;
	if (a >= MOD)
		 a-= MOD;
}
int add(int a, int b)
{
	sadd(a, b);
	return a;
}
void smul(int &a, int b)
{
	a = (a * 1LL * b) % MOD;
}
int mul(int a, int b)
{
	return  (a * 1LL * b) % MOD;
}
int fpow(int x, int n)
{
	if (n == 0) return 1;
	int a = fpow(x, n >> 1);
	smul(a, a);
	if (n & 1) smul(a, x);
	return a;
}
int rev(int x)
{
	return fpow(x, MOD - 2);
}
int divi(int a, int b)
{
	return mul(a, rev(b) );
}
void sdivi(int &a, int b)
{
	smul(a, rev(b) );
}

const int N = (int) 1e7 + 100;
int ans[N];
int sum[N];

void solve()
{
	int n, k;
	scanf("%d%d", &n, &k);
	ans[1] = 1;
	sum[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		ans[i] = sum[i - 2];
		sdivi(ans[i], i - 1);
		sum[i] = add(sum[i - 1], ans[i] );
	}
	int answ = mul(ans[k], ans[n - k + 1] );
	answ = (MOD + 1 - answ) % MOD;
	printf("%d\n", answ);
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Case #%d: ", i);
		eprintf("Case #%d .. %d\n", i, n);
		solve();
	}


}

int main(int argc, char **)
{
	if (argc == 1)
		multitest();
	else
		solve();

	return 0;
}


