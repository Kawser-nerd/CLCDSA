#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <ctime>
using namespace std;

typedef long long int64;
int data[105][105];
int next[105][105];
int main()
{
	int cas;scanf("%d", &cas);
	int id = 1;
	while (cas--)
	{
		memset(data, 0, sizeof data);
		int r;scanf("%d", &r);
		while (r--)
		{
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for (int i = x1; i <= x2; ++i)
			for (int j = y1; j <= y2; ++j) data[i][j] = 1;
		}
		int used = 0;
		for (;;)
		{
			int found = 0;
			for (int i = 1; i <= 100; ++i)
			for (int j = 1; j <= 100; ++j)
			if (data[i][j] == 1) found = 1;
			if (!found) break;
			memset(next, 0, sizeof next);
			for (int i = 1; i <= 100; ++i)
			for (int j = 1; j <= 100; ++j)
			{
				if (data[i][j] == 0)
				{
					if (data[i-1][j] == 1 && data[i][j-1] == 1)
					{
						next[i][j] = 1;
					}
				}
				else
				{
					if (data[i-1][j] == 0 && data[i][j-1] == 0)
					{
						next[i][j] = 0;
					}
					else
					{
						next[i][j] = 1;
					}
				}
			}
			memcpy(data, next, sizeof data);
			++used;
		}
		printf("Case #%d: %d\n", id++, used);
	}
	return 0;
}
