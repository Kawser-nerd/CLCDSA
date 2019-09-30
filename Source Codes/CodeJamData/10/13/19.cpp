#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

const long double eps = 1e-9;

int a1, a2, b1, b2;

void Load()
{
	scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
}

int RUP(long double a)
{
	if (fabs(a - (int)a) < eps) return (int)a;
	else return (int)a + 1;
}

void Solve()
{
	int a;
	long long ans = 0;
	long double q = (1 + sqrt(5.0)) / 2;
	for (a = a1; a <= a2; a++)
	{
		int cl, cr;
		if (a == 1) cl = cr = 1;
		else
		{
			cl = RUP(a / q);
			cr = cl + a - 1;
		}
		//cerr << "a = " << a << " cl = " << cl << " cr = " << cr << "\n";
		int ll, rr;
		ll = max(b1, cl);
		rr = min(b2, cr);
		int cans = b2 - b1 + 1;
		if (ll <= rr)
		{
			cans -= (rr - ll + 1);
		}
		ans += cans;
	}
	cout << ans;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int nt, it;
	scanf("%d", &nt);
	for (it = 0; it < nt; it++)
	{
		printf("Case #%d: ", it + 1);
		Load();
		Solve();
		printf("\n");
	}
	return 0;
}