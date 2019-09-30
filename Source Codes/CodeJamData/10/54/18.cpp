#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef std::pair<int, int> pii;

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

int base;
const ll mod = 1000000007;


int stack[1000];
int temp[1000];

int use[100];
bool check(int n)
{
	for(int i = 0; i < n; i++)
		temp[i] = stack[i];
	for(int j = 0; j < 10; j++)
	{
		clr(use);
		for(int i = 0; i < n; i++)
		{
			if (temp[i] == 0)
				continue;
			if (use[temp[i] % base])
				return false;
			use[temp[i] % base] = 1;
			temp[i] /= base;
		}
	}
	return true;
}

ll rec(int sum, int last, int depth)
{
	if (sum == 0)
	{
		if (check(depth))
			return 1;
		else
			return 0;
	}
	ll ans = 0;
	for(int i = 1; i <= last && i <= sum; i++)
	{
		stack[depth] = i;
		ans += rec(sum - i, i - 1, depth + 1);
	}
	return ans % mod;
}



void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	int sum;
	scanf("%d%d", &sum, &base);
	printf("%lld\n", rec(sum, sum, 0) % mod);
}




int main()
{

	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
