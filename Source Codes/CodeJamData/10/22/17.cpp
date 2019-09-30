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

const int N = 100;

int x[N], v[N];


int main()
{
	freopen(TASKNAME "input.txt", "r", stdin);
	freopen(TASKNAME "output.txt", "w", stdout);


#ifdef DBG1
#if DBG2

	freopen(TASKNAME ".err", "w", stderr);
#endif
#endif

	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		int n, k, b, t;
		scanf("%d%d%d%d", &n, &k, &b, &t);
		for (int i = 0; i < n; ++i)
			scanf("%d", &x[i]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);

		int res = 0;
		int cnt = 0;
		for (int i = n - 1; i >= 0 && k; --i)
		{
			if ((b - x[i]) <= v[i] * t)
			{
				res += cnt;
				--k;
			}
			else
				++cnt;
		}

		if (k == 0)
			printf("Case #%d: %d\n", ii, res);
		else
			printf("Case #%d: IMPOSSIBLE\n", ii);
	}

	return 0;
}