/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct Horse {
	double x;
	int s;
	bool operator < ( Horse h ) const { return x < h.x; } 
};

void solve() {
	int n, d;
	scanf("%d%d", &d, &n);
	vector<Horse> p(n + 1);
	double t = 0;
	forn(i, n) {
		scanf("%lf%d", &p[i].x, &p[i].s);
		t = max(t, (d - p[i].x) / p[i].s);
	}
	// p[n] = {d, 0};
	// sort(p.begin(), p.end());
	// double t = 0;
	// while (p.size() > 1U) {
	// 	int event = -1;
	// 	double event_t = 0;
	// 	forn(i, p.size() - 1) {
	// 		if (p[i].s > p[i + 1].s) {
	// 			double it = (p[i + 1].x - p[i].x) / (p[i].s - p[i + 1].s);
	// 			if (event == -1 || it < event_t)
	// 				event = i, it = event_t;
	// 		}
	// 	}
	// 	assert(event != -1);

	// }
	printf("%.9f\n", d / t);
}

int main() {
	int tn;
	scanf("%d", &tn);
	for (int t = 1; t <= tn; t++) {
		printf("Case #%d: ", t);
		fprintf(stderr, "Case #%d\n", t);
		solve();
	}
}