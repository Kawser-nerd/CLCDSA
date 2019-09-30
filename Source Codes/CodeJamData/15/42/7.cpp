/*
	Author: elfness@UESTC
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long LL;
int _, n;
double V, T, r[120], t[120], v[120];
int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
	scanf("%d", &_);
	for(int ca = 1; ca <= _; ++ca)
	{
		scanf("%d%lf%lf", &n, &V, &T);
		for(int i = 0; i < n; ++i)
		scanf("%lf%lf", &r[i], &t[i]);
		printf("Case #%d: ", ca);
		if(n == 2 && t[0] == t[1])
		{
			--n;
			r[0] += r[1];
		}
		if(n == 1)
		{
			if(t[0] == T) printf("%.9f\n", V / r[0]);
			else puts("IMPOSSIBLE");
		}
		else
		{
			v[1] = (T - t[0]) * V / (t[1] - t[0]);
			v[0] = V - v[1];
			if(v[0] < 0.0 || v[1] < 0.0) puts("IMPOSSIBLE");
			else printf("%.9f\n", max(v[0] / r[0], v[1] / r[1]));
		}
	}
	return 0;
}
