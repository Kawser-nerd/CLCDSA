#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>

using namespace std;

char buf[1000000];
__int64 ans;
int n;
__int64 a, b, c, d, x, y, m;
int t[3][3];

void init()
{
	scanf("%d%I64d%I64d%I64d%I64d%I64d%I64d%I64d", &n, &a, &b, &c, &d, &x, &y, &m);
	memset(t, 0, sizeof(t));
	for (int i = 0; i < n; ++i)
	{
		++t[x%3][y%3];
		x = (a * x + b) % m;
		y = (c * y + d) % m;
	}
}

void process()
{
	ans = 0;
	for (int i1 = 0; i1 < 3; ++i1)
		for (int j1 = 0; j1 < 3; ++j1)
			for (int i2 = 0; i2 < 3; ++i2)
				for (int j2 = 0; j2 < 3; ++j2)
				{
					int i3 = (9 - i1 - i2) % 3, j3 = (9 - j1 - j2) % 3;
					if (i2<i1 || i2==i1 && j2<j1)
						continue;
					if (i3<i1 || i3==i1 && j3<j1)
						continue;
					if (i3<i2 || i3==i2 && j3<j2)
						continue;
					__int64 t1 = t[i1][j1], t2 = t[i2][j2], t3 = t[i3][j3], sm = 1;
					if (i2==i1 && j2==j1)
					{
						--t2;
						++sm;
					}
					if (i3==i1 && j3==j1)
					{
						--t3;
						++sm;
					}
					if (i3==i2 && j3==j2)
					{
						--t3;
						++sm;
					}
					if (sm==4)
						sm = 6;
					ans += t1 * t2 * t3 / sm;
				}
}

void print()
{
	static int id = 0;
	++id;
	printf("Case #%d: %I64d\n", id, ans);
}

int main()
{
	freopen("a.txt", "rt", stdin);
	freopen("a_out.txt", "wt", stdout);
	int tt;
	scanf("%d", &tt);
	for (int i = 0; i < tt; ++i)
	{
		init();
		process();
		print();
	}
}
