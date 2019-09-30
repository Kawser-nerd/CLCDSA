#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef unsigned long long my_t;

my_t x, y;

my_t divide(my_t s, my_t e)
{
	my_t mid;
	my_t frt;
	my_t rt;
	while (1)
	{
		if (s > e)
		{
			return rt;
		}
		mid = (s + e) >> 1;
		frt = 2 * mid * x + 2 * mid * mid - mid;
		if (frt == y)
			return mid;
		else if (frt < y)
		{
			s = mid + 1;
			rt = mid;
		}
		else
		{
			e = mid - 1;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, t;
	int i, j;
	my_t mx;
	my_t tmp;
	my_t rt;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		scanf("%lld%lld", &x, &y);
		mx = y / (2 * x - 1);
		tmp = (my_t)(sqrt((double)(y / 2)));
		if (mx > tmp) 
			mx = tmp;
		if (2 * mx * x + 2 * mx * mx - mx <= y)
			mx++;

		rt = divide(0, mx);
		printf("%lld\n", rt);
	}
	
	return 0;
}

