#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Point
{
	ll x, y;

	Point() : x(), y() {}
	Point (ll _x, ll _y) : x(_x), y(_y) {}

	void scan()
	{
		scanf("%lld%lld", &x, &y);
	}

	Point operator + (Point a)
	{
		return Point(x + a.x,y + a.y);
	}
	Point operator - (Point a)
	{
		return Point(x - a.x, y - a.y);
	}
	ll operator % (Point a)
	{
		return x * a.x + y * a.y;
	}
	ll operator * (Point a)
	{
		return x * a.y - y * a.x;
	}
};

const int N = 3030;
int n;
Point a[N];
Point b[N];

int getSemiplane(Point A)
{
	if (A.y > 0) return 0;
	if (A.y == 0 && A.x > 0) return 0;
	return 1;
}

bool cmp(const Point &A, const Point &B)
{
	Point v = A;
	Point u = B;
	int x = getSemiplane(v);
	int y = getSemiplane(u);
	if (x != y)
		return x < y;
	return v * u > 0;
}

void solve()
{
	int ans = n;
	if (ans == 0)
	{
		printf("%d\n", ans);
		return;
	}
	sort(a, a + n, cmp);
	int idx1 = 1;
	int idx2 = 1;
	for (int i = 0; i < n; i++)
	{
		if (idx1 == i) idx1 = (idx1 + 1) % n;
		if (idx2 == i) idx2 = (idx2 + 1) % n;
		while(idx1 != i && a[i] * a[idx1] > 0) idx1 = (idx1 + 1) % n;
		while(idx2 != i && a[i] * a[idx2] >= 0) idx2 = (idx2 + 1) % n;
		if (idx1 > i)
			ans = min(ans, idx1 - i - 1);
		else
			ans = min(ans, n - i - 1 + idx1);
		if (idx2 > i)
			ans = min(ans, n - idx2 + i);
		else
			ans = min(ans, i - idx2);
	}
	printf("%d\n", ans);
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int q = 1; q <= t; q++)
	{
		printf("Case #%d:\n", q);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			b[i].scan();
		n--;
		for (int i = 0; i <= n; i++)
		{
			int sz = 0;
			for (int j = 0; j <= n; j++)
			{
				if (i == j) continue;
				a[sz++] = b[j] - b[i];
			}
			solve();
		}
	}

	return 0;
}
