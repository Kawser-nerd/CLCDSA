#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <string>
#include <ctime>

using namespace std;

#define rep(x, y, z) for(int x = (y), end##x = (z); x < end##x; x++)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL_DEBUG

#define DebugPrint(...) fprintf(stderr, __VA_ARGS__);

#else

#define DebugPrint(...)

#endif

typedef long long ll;
typedef pair<int, int> pii;

void test(int testNum);

int main()
{
	//
#ifdef LOCAL_DEBUG

	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

#else

	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);

#endif

	clock_t cl = clock();

	int tc;
	scanf("%d", &tc);

	rep(i, 0, tc)
		test(i+1);

#ifdef LOCAL_DEBUG

	fprintf(stderr, "\nTime used: %lf\n", (clock() - cl) / (double)CLOCKS_PER_SEC);

#endif

	return 0;
}

void test(int testNum)
{
	printf("Case #%d: ", testNum);
	
	int lawn[105][105];

	int n, m;
	scanf("%d%d", &n, &m);

	rep(i, 0, n)
	{
		rep(j, 0, m)
		{
			scanf("%d", &(lawn[i][j]));
		}
	}

	int cutCount = n*m;

	while (cutCount > 0)
	{
		bool found = 0;

		int minVal = 100500;

		rep(i, 0, n)
		{
			rep(j, 0, m)
			{
				if (lawn[i][j] != -1 && lawn[i][j] < minVal)
					minVal = lawn[i][j];
			}
		}

		rep(i, 0, n)
		{
			int curVal = -1;
			rep(j, 0, m)
			{
				if (curVal != -1 && curVal != lawn[i][j] && lawn[i][j] != -1)
				{
					curVal = -2;
					break;
				}
				if (lawn[i][j] != -1)
				{
					curVal = lawn[i][j];
				}
			}

			if (curVal == minVal)
			{
				found = 1;
				rep(j, 0, m)
				{
					if (lawn[i][j] != -1)
					{
						lawn[i][j] = -1;
						cutCount--;
					}
				}
			}
		}

		rep(j, 0, m)
		{
			int curVal = -1;
			rep(i, 0, n)
			{
				if (curVal != -1 && curVal != lawn[i][j] && lawn[i][j] != -1)
				{
					curVal = -2;
					break;
				}
				if (lawn[i][j] != -1)
				{
					curVal = lawn[i][j];
				}
			}

			if (curVal == minVal)
			{
				found = 1;
				rep(i, 0, n)
				{
					if (lawn[i][j] != -1)
					{
						lawn[i][j] = -1;
						cutCount--;
					}
				}
			}
		}

		if (!found)
			break;
	}

	if (cutCount == 0)
		printf("YES\n");
	else
		printf("NO\n");
}