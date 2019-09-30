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

ll x[50];
ll v[50];

void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	int n, k;
	ll b,t;
	scanf("%d%d%lld%lld", &n, &k, &b, &t);
	for(int i = 0; i < n; i++)
		scanf("%lld", &x[i]);
	for(int i = 0; i < n; i++)
		scanf("%lld", &v[i]);
	int bad = 0;
	int ans = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		if (b-x[i] > t * v[i])
			bad++;
		else
		{
			ans += bad;
			k --;
		}
		if (k == 0)
			break;
	}
	if (k)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n", ans);


}


int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
