#include <bits/stdc++.h>
using namespace std;

int n, k;
double u;
double p[55];

void read() {
	cin >> n >> k;
	cin >> u;
	for(int i = 0 ; i < n ; i++)
		cin >> p[i];
}

bool can(double x) {
	double ret = 0;
	for(int i = 0 ; i < n ; i++)
		ret += max(0.0, x - p[i]);
	return ret < u + 1e-9;
}

double solve() {
	double lo = 0, hi = 1;
	for(int i = 0 ; i < 50 ; i++) {
		double mid = (lo + hi) / 2;
		if(can(mid))
			lo = mid;
		else
			hi = mid;
	}

	double ret = 1;
	for(int i = 0 ; i < n ; i++)
		ret = ret * max(lo, p[i]);
	return ret;
}

int main() {
	int t; cin >> t;
	for(int tc = 1 ; tc <= t ; tc++) {
		read();
		double ret = solve();

		printf("Case #%d: %.9lf\n", tc, ret);
	}
	return 0;
}