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

const int maxn = 500500;
char str[maxn];
bool eq(double x, double y)
{
	return fabs(x - y) < 1e-13;
}
bool ls(double x, double y)
{
	return x < y && !eq(x, y);
}


void solve()
{
	int n;
	double d;
	scanf("%d%lf", &n, &d);
	int ans = -1;
	double x = 2;

	scanf("%s", str);
	for (int i = 0; i < n; i++)
	{
		int sum = 0, cnt = 0;
		for (int j = i; j < n; j++)
		{
			sum += str[j] - '0';
			cnt++;
			double cur = sum / (double) cnt;
			cur = fabs(cur - d);
			if (ls(cur, x) || (eq(cur, x) && j < ans) )
			{
				x = cur;
				ans = i;
			}
		}
	}
	eprintf("%.10lf\n", x);
	printf("%d\n", ans);
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


