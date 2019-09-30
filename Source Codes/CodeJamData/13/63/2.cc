#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<double> vx, vy;

bool done;
void doit(double x1, double y1, double x2, double y2) {
	if (done) return;
	vector<double> u, d;
	double ln = hypot(x2-x1, y2-y1);
	for (int i = 0; i < N; i++) {
		double cp = ((vx[i]-x1)*(y2-y1) - (vy[i]-y1)*(x2-x1)) / ln;
		if (fabs(cp) < 1e-8) return;
		if (cp > 0) {
			u.push_back(((vx[i]-x1)*(x2-x1) + (vy[i]-y1)*(y2-y1)) / ln);
		} else {
			d.push_back(((vx[i]-x1)*(x2-x1) + (vy[i]-y1)*(y2-y1)) / ln);
		}
	}
	if (u.size() != d.size()) return;
	sort(u.begin(), u.end());
	sort(d.begin(), d.end());
	if (fabs(u[N/4]-u[N/4-1]) < 1e-8) return;
	if (fabs(d[N/4]-d[N/4-1]) < 1e-8) return;
	if (max(u[N/4-1], d[N/4-1]) >= min(u[N/4], d[N/4])) return;
	double x = (max(u[N/4-1], d[N/4-1]) + min(u[N/4], d[N/4])) / 2;
	printf(" %.9lf %.9lf", x1 + (x2-x1)/ln*x, y1 + (y2-y1)/ln*x);
	if (fabs(x) > 1e-3) {
		printf(" %.9lf %.9lf\n", x1, y1);
	} else {
		printf(" %.9lf %.9lf\n", x2, y2);
	}
	done = true;
}

main() {
	int T, prob=1;
	for (cin >> T; T--;) {
		cin >> N;
		N *= 4;
		vx.resize(N); vy.resize(N);
		for (int i = 0; i < N; i++) cin >> vx[i] >> vy[i];
		cout << "Case #" << prob++ << ":";
		done = false;
		for (int i = 0; i < N && !done; i++)
		for (int j = 0; j < N && !done; j++) {
			doit(vx[i]+0.00021, vy[i]+0.00013, vx[j]+0.00011, vy[j]+0.00007);
			doit(vx[i]-0.00021, vy[i]-0.00012, vx[j]-0.00011, vy[j]-0.00005);
		}
		if (!done) cout << " IMPOSSIBLE" << endl;
	}
}
