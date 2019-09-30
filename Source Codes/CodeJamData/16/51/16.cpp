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


const int N = (int) 2e5 + 100;
char str[N];

void solve()
{
	scanf("%s", str);
	int n = strlen(str);
	int ans = 0;
	int sz = 0;
	for (int i = 0; i < n; i++)
	{
		if (sz != 0 && str[i] == str[sz - 1] )
		{
			sz--;
			ans += 10;
		}
		else
		{
			str[sz++] = str[i];
		}
	}
	ans += (sz / 2) * 5;
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


