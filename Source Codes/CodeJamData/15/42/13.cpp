#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;

const int IT = 400;
const int N = 110;
const double eps = 1e-5;
const double INF = 2e7;

bool eq(double x, double y)
{
	return fabs(x - y) < eps;
}
bool ls(double x, double y)
{
	return x < y && !eq(x, y);
}
bool lseq(double x, double y)
{
	return x < y || eq(x, y);
}

struct Item
{
	double T, v;

	Item() : T(), v() {}
	Item(double _T, double _v) : T(_T), v(_v) {}

	void scan()
	{
		scanf("%lf%lf", &v, &T);
	}

	bool operator < (const Item &a) const
	{
		return ls(T, a.T);
	}
};

Item a[N];
double L, R;
int n;
double T, V;

double check(double tm)
{
//	printf("CHECK %.5lf\n", tm);
	int r = 0;
	while(ls(a[r].T, 0)) r++;
	int l = r - 1;
	double need = V;
	while(need > 0 && r < n && eq(a[r].T, 0))
	{
		need -= tm * a[r].v;
		r++;
	}
	if (need <= 0) return true;
	double lx = 0, rx = 0;
	if (l >= 0)
		lx = a[l].v * tm;
	if (r < n)
		rx = a[r].v * tm;
	while(need > 0 && l >= 0 && r < n)
	{
		double lm = lx * fabs(a[l].T), rm = rx * a[r].T;
		if (lm <= rm)
		{
			need -= lx + lm / a[r].T;
			rx -= lm / a[r].T;
			l--;
			if (l >= 0)
				lx = a[l].v * tm;
		}
		else
		{
			need -= rx + rm / fabs(a[l].T);
			lx -= rm / fabs(a[l].T);
			r++;
			if (r < n)
				rx = a[r].v * tm;
		}
	}
//	printf("need = %.5lf\n", need);
	return (need <= 0);
}

void solve()
{
	scanf("%d%lf%lf", &n, &V, &T);
	for (int i = 0; i < n; i++)
		a[i].scan();
	sort(a, a + n);
	if (ls(T, a[0].T) || ls(a[n - 1].T, T))
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	for (int i = 0; i < n; i++)
		a[i].T -= T;

	L = 0;
	R = INF;

	for (int it = 0; it < IT; it++)
	{
		double x = (L + R) / 2;
		if (check(x))
			R = x;
		else
			L = x;
	}
	printf("%.10lf\n", R);
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		printf("Case #%d: ", i);
		solve();
	}

	return 0;
}
