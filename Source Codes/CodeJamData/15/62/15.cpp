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

const int mod = (int) 1e9 + 7;
void add(int &a, int b)
{
	a += b;
	if (a < 0)
		a += mod;
	if (a >= mod)
		a -= mod;
}
int sum(int a, int b)
{
	add(a, b);
	return a;
}
int mul(int a, int b)
{
	return (a * 1LL * b) % mod;
}
int sqr(int x)
{
	return mul(x, x);
}

const int maxn = (int) 1e6 + 100; // TODO

int ri[maxn], fact[maxn], rfact[maxn];


void init()
{
	fact[0] = rfact[0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		if (i == 1)
			ri[i] = 1;
		else
			ri[i] = sum(0, -mul(mod / i, ri[mod % i] ) );
		fact[i] = mul(fact[i - 1], i);
		rfact[i] = mul(rfact[i - 1], ri[i] );
	}
}

int C(int a, int b)
{
	if (b < 0 || b > a)
		return 0;
	return mul(fact[a], mul(rfact[b], rfact[a - b] ) );
}


int dp[maxn]; 
int cntNonStat[maxn];
int bad[maxn];

void precalc()
{
	dp[0] = 1;
	cntNonStat[0] = 1;
	
	for (int i = 1; i < maxn; i++)
	{
		cntNonStat[i] = fact[i];		
		add(cntNonStat[i], -fact[i - 1] );
		add(cntNonStat[i], -mul(i - 1, bad[i - 1] ) );
		add(cntNonStat[i], mul(i - 1, cntNonStat[i - 2] ));	
		
		bad[i] = sum(fact[i], -cntNonStat[i] );
	}
	for (int i = 0; i < maxn; i++)
		dp[i] = mul(fact[i], cntNonStat[i] );
}

void solve()
{
	int n, x;
	scanf("%d%d", &n, &x);

	int ans = 0;
	for (int i = x; i <= n; i++)
	{
		add(ans, mul(mul(sqr(C(n, i) ), fact[i] ), dp[n - i] ) );
	}

	printf("%d\n", ans);
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	init();
	precalc();

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


