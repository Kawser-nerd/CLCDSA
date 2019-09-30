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
struct Pt
{
	int64 x, v;
	int operator < (const Pt& o) const
	{
		return x < o.x;
	}
};
Pt data[100];
int main()
{
	int cas;scanf("%d", &cas);
	int id = 1;
	while (cas--)
	{
		int64 n, k, b, t;
		cin >> n >> k >> b >> t;
		for (int i = 0; i < n; ++i)
		{
			cin >> data[i].x;
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> data[i].v;
		}
		sort(data, data+n);
		int can = 0;
		for (int i = 0; i < n; ++i)
		{
			if (t  * data[i].v >= b - data[i].x) ++can;
		}
		if (can < k) {printf("Case #%d: IMPOSSIBLE\n", id++);continue;}
		if (k == 0) {printf("Case #%d: 0\n", id++);continue;}
		int blocked = 0;
		int have = 0;
		int ans = 0;
		for (int i = n - 1; have < k && i >= 0; --i)
		{
			if (t  * data[i].v < b - data[i].x) ++blocked;
			else
			{
				++have;
				ans += blocked;
			}
		}
		printf("Case #%d: %d\n", id++, ans);
	}
	return 0;
}
