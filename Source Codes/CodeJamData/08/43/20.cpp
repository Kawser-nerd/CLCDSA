#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;

double r[1000];
int x[1000], y[1000], z[1000], p[1000];

bool test() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (r[i] + r[j] < abs(x[i] - x[j]) + abs(y[i] - y[j]) + abs(z[i] - z[j])) return 0;
		}
	}
	return 1;
}

double solve() {
	int i, t;
	double l, h, m;
	for (i = 0; i < n; i++) {
		if (x[i] != x[0] || y[i] != y[0] || z[i] != z[0]) break;
	}
	if (i == n) return 0;
	l = 0;
	h = 1e7;
	for (t = 0; t < 100; t++) {
		m = (l + h) / 2;
		for (i = 0; i < n; i++) r[i] = p[i] * m;
		if (test()) {
			h = m;
		}
		else {
			l = m;
		}
	}
	return m;
}

int main() {
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int testcases;
	int i, t;
	scanf("%d", &testcases);
	for (t = 0; t < testcases; t++) {
		printf("Case #%d: ", t+1);
		scanf("%d",&n);
		for (i = 0; i < n; i++) {
			scanf("%d%d%d%d",&x[i],&y[i],&z[i],&p[i]);
		}
		printf("%.10lf\n",solve());
	}
	return 0;
}
