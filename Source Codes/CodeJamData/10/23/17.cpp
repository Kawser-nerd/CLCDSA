#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cmath>

#include <cstdarg>

#pragma comment(linker,"/STACK:128000000")

#define DBG2 1

void dbg(const char * fmt, ...)
{
#ifdef DBG1
#if DBG2
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
#endif
#endif
}

#ifdef DBG1
#define LL "%I64d"
#else
#define LL "%lld"
#endif


using namespace std;

#define clr(a) memset(a,0,sizeof(a))
#define fill(a,b) memset(a,b,sizeof(a))

#define TASKNAME ""

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int> pii;

bool use[1024][1024];
ll dp[1024][1024];
ll c[1024][1024];

const int P = 100003;

ll findRes(int n, int num)
{
	if (use[n][num])
		return dp[n][num];

	use[n][num] = 1;
	ll & ans = dp[n][num];

	if (num == 1)
		return ans = 1;

	for (int i = 1; i < num; ++i)
	{
		if (i + (n - num) < num)
			continue;

		ans = (ans + findRes(num, i) * c[n - num - 1][num - i - 1]) % P;
	}

	return ans;
}

int main()
{
	freopen(TASKNAME "input.txt", "r", stdin);
	freopen(TASKNAME "output.txt", "w", stdout);


#ifdef DBG1
#if DBG2

	freopen(TASKNAME ".err", "w", stderr);
#endif
#endif

	c[0][0] = 1;
	for (int i = 1; i <= 600; ++i)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
	}

	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		int n;
		scanf("%d", &n);
		int res = 0;
		for (int i = 1; i < n; ++i)
			res = (res + findRes(n, i)) % P;

		printf("Case #%d: %d\n", ii, res);
	}

	return 0;
}