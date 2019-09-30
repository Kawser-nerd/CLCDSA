#include <algorithm>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

const int MAXN = 500;

int N;
long long int xc, yc, zc, vx, vy, vz;

void read_data()
{
	long long int xt, yt, zt, vx0, vy0, vz0;

	xc = 0; yc = 0; zc = 0; vx = 0; vy = 0; vz = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lld%lld%lld%lld%lld%lld", &xt, &yt, &zt, &vx0, &vy0, &vz0);
		xc += xt; yc += yt; zc += zt;
		vx += vx0; vy += vy0; vz += vz0;
	}
}

void solve()
{
	long double a = vx*vx + vy*vy + vz*vz, b = 2 * (xc*vx + yc*vy + zc*vz), c = xc*xc + yc*yc + zc*zc;

	if (vx == 0 && vy == 0 && vz == 0) {
		printf("%.10lf %.10lf\n", sqrtl(c) / N, 0);
		return;
	}

	long double t = -b / (2*a);

	if (t < 0) {
		printf("%.10lf %.10lf\n", sqrtl(c) / N, 0);
		return;
	}

	printf("%.10lf %.10lf\n", sqrtl(c - b*b / (4*a)) / N, fabsl(t));
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; ++t) {
		printf("Case #%d: ", t);
		read_data();
		solve();
	}

	return 0;
}
