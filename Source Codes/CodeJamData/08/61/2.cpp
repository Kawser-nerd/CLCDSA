#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_N = 1000;
const int INF = 1000000000;

int hN[MAX_N];
int wN[MAX_N];


bool inRange(int x, int l, int r)
{
	return (l <= x && x <= r);
}
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("a-large.out", "w", stdout);
	int testNum;
	scanf("%d", &testNum);
	for (int testInd = 1; testInd <= testNum; testInd++)
	{
		int n;
		scanf("%d", &n);
		int leftH = INF;
		int rightH = -INF;
		int leftW = INF;
		int rightW = -INF;
		int m = 0;
		bool hasBird = false;
		for (int i = 0; i < n; i++)
		{
			int h, w;
			char buf[100];
			scanf("%d%d%s", &h, &w, buf);
			bool bird = true;
			if (buf[0] == 'N')
			{
				scanf("%s", buf);
				bird = false;
			}
			if (bird)
			{
				hasBird = true;
				leftH = min(leftH, h);
				rightH = max(rightH, h);
				leftW = min(leftW, w);
				rightW = max(rightW, w);
			}
			else
			{
				hN[m] = h;
				wN[m] = w;
				m++;
			}
		}

		printf("Case #%d:\n", testInd);
		int p;
		scanf("%d", &p);
		while (p--)
		{
			int h, w;
			scanf("%d%d", &h, &w);
			if (!hasBird)
			{
				bool notbird = false;
				for (int i = 0; i < m; i++)
					if (hN[i] == h && wN[i] == w) 
					{
						notbird = true;
						break;
					}
				if (notbird)
					puts("NOT BIRD");
				else
					puts("UNKNOWN");
			}
			else
			{
				if (inRange(h, leftH, rightH) && inRange(w, leftW, rightW))
				{
					puts("BIRD");
				}
				else
				{
					bool notbird = false;
					for (int i = 0; i < m; i++)
						if (hN[i] < leftH)
							if (wN[i] < leftW)
								notbird |= (h <= hN[i] && w <= wN[i]);
							else if (wN[i] <= rightW)
								notbird |= (h <= hN[i]);
							else
								notbird |= (h <= hN[i] && w >= wN[i]);
						else if (hN[i] <= rightH)
							if (wN[i] < leftW)
								notbird |= (w <= wN[i]);
							else if (wN[i] <= rightW) //not chance
								notbird |= false;
							else
								notbird |= (w >= wN[i]);
						else
							if (wN[i] < leftW)
								notbird |= (h >= hN[i] && w <= wN[i]);
							else if (wN[i] <= rightW)
								notbird |= (h >= hN[i]);
							else
								notbird |= (h >= hN[i] && w >= wN[i]);
					if (notbird)
						puts("NOT BIRD");
					else
						puts("UNKNOWN");
				}
			}
		}
	}
	return 0;
}



