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


const int H = (int) 2505;
int cnt[H];

void solve()
{
	memset(cnt, 0, sizeof cnt);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n - 1; i++)
		for (int j = 0; j < n; j++)
		{
			int x;
			scanf("%d", &x);
			cnt[x]++;
		}
	for (int i = 0; i < H; i++)
		if (cnt[i] & 1)
			printf("%d ", i);
	printf("\n");
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


