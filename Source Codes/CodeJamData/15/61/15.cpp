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

const int maxn = (int) 1e6 + 100;
char s[maxn];

int toL[maxn][10];
int maxr[10][maxn];


void solve()
{
	scanf("%s", s);
	int n = strlen(s);


	for (int i = 0; i < n; i++)
		s[i] -= '0';
	for (int i = 1; i < 10; i++)
		toL[0][i] = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (i != 0)
				toL[i][j] = toL[i - 1][j];
		}
		toL[i][(int) s[i] ] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= n; j++)
			maxr[i][j] = j;
	}

	for (int cost = 1; ; cost++)
	{
/*		eprintf("cost = %d\n", cost - 1);
		for (int i = 0; i < n; i++)
			eprintf("%d ", maxr[0][i] );
		eprintf("\n");
*/		
		for (int i = 9; i > 0; i--)
			for (int j = 0; j <= n; j++)
				maxr[i][j] = maxr[i - 1][j];
		
		for (int i = 0; i <= n; i++)
		{
			if (maxr[1][i] == n)
			{
				maxr[0][i] = n;
				continue;
			}
			for (int mid = 1; mid <= min(9, cost); mid++)
			{
				int pos = toL[maxr[mid][i] ][mid] + 1;
				if (pos <= i)
					continue;
				maxr[0][i] = max(maxr[0][i], maxr[mid][pos] );
			}
		}


		if (maxr[0][0] == n)
		{
			eprintf("... %d\n", cost);
			printf("%d\n", cost);
			break;
		}
	}
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


