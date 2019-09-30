#include <bits/stdc++.h>
using namespace std;
int t;
int d, n;
int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d%d", &d, &n);
		double a, b;
		double woc = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &a, &b);
			woc = max(woc, (d - a) / b);
		}
		printf("Case #%d: %.6f\n", tt, d / woc);
	}
	return 0;
}