#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

pair < int, int > p[250];
int n;
int d;

bool check(double t)
{
	double cur = -1e20;
	for (int i = 1; i <= n; i ++)
	{
		int m = p[i].second;
		int x = p[i].first;
		double l = (double)(x) - t, r;
		l = max(l, cur);
		r = l + (double)(m - 1) * (double)(d);
		if (r > (double)(x) + t) return false;
		cur = r + (double)(d);
	}
	return true;
}

void solve(int test)
{
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", &p[i].first, &p[i].second);
	//sort(p + 1, p + n + 1);
	double l = 0.0, r = 1e13;
	int t = 0;
	while (t < 200)
	{
		t ++;
		double key = (l + r) / 2.0;
		if (check(key))
			r = key; else l = key;
	}
	printf("Case #%d: %.10lf\n", test, r);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;
	scanf("%d\n", &test);
	for (int i = 1; i <= test; i ++)
		solve(i);
	return 0;
}