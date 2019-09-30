#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#define clr(a) memset(a, 0, sizeof(a))


typedef long long ll;

#define DEBUG 1

void dbg(const char * fmt, ...)
{
#if DEBUG
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);
#endif
}


const int mod = 100003;

ll c[1000][1000];
ll dp[1000][1000];

void init()
{
	clr(c);
	clr(dp);
	for(int i = 0; i < 1000; i++)
	{
		c[i][0] = c[i][i] = 1;
		for(int j = 1; j < i; j++)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
	}
	for(int n = 2; n <= 500; n++)
	{
		dp[n][1] = 1;
		for(int l = 2; l < n; l++)
		{
			for(int i = 1; i < l; i++)
			{
				dp[n][l] += dp[l][i] * c[n-l-1][l-i-1];
				dp[n][l] %= mod;
			}
		}
	}

}

void solve(int test_case)
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += dp[n][i];
	ans %= mod;
	printf("Case #%d: %d\n", test_case, ans);
}



int main()
{
	init();
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
