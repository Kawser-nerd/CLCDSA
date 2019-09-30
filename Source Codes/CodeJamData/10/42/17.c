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
int choose[4096<<1];
int price[4096<<1];
int need[1024<<1];
int lost[1024<<1];
int checked[1024<<1];
int main()
{
	int cas;scanf("%d", &cas);
	int id = 1;
	while (cas--)
	{
		int p;scanf("%d", &p);
		for (int i = 1; i <= (1 << p) ; ++i) scanf("%d", need+i);
		for (int x = p; x >= 1; --x)
		{
			int start = 1 << (x - 1);
			for (int j = start; j < 2 * start; ++j) scanf("%d", price+j);
		}
		
		int ans = 0;
		memset(choose, 0, sizeof choose);
		memset(checked, 0, sizeof checked);
		for (;;)
		{
			int pos = 0, value = 200000000;
			for (int i = 1; i <= (1<<p); ++i)
			if (checked[i] == 0)
			{
				if (need[i] < value) value = need[i], pos = i;
			}
			if (pos == 0) break;
			checked[pos] = 1;
			int tot_need = p - value;
			int parent = ((1 << p) + pos - 1) >> 1;
			//cout << pos << " " << tot_need << endl;
			int path[20];
			int top = 0;
			
			while (parent >= 1)
			{
				if (choose[parent]) --tot_need;
				path[top++] = parent;
				parent >>= 1;
			}
			for (int i = top - 1; tot_need > 0 && i >= 0; --i)
			{
				if (choose[path[i]] == 0)
				{
					choose[path[i]] = 1;
					ans += price[path[i]];
					--tot_need;
				}
			}
			
		}

		printf("Case #%d: %d\n", id++, ans);
	}
	return 0;
}
