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

char s[1000];
set <string> paths;

void parse(char * s)
{
	string cur = "/";
	int len = strlen(s);
	s[len] = '/';
	for (int i = 1; i <= len; ++i)
	{
		if (s[i] == '/')
			paths.insert(cur);
		cur += s[i];
	}
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

	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		gets(s);

		paths.clear();

		for (int i = 0; i < n; ++i)
		{
			gets(s);
			parse(s);
		}

		int cnt1 = paths.size();

		for (int i = 0; i < m; ++i)
		{
			gets(s);
			parse(s);
		}

		printf("Case #%d: %d\n", ii, paths.size() - cnt1);
	}

	return 0;
}