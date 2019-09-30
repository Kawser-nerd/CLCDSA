#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cassert>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string>
#include <utility>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long int64;

const double EPS = 1E-8;

int64 x[4], xx[4], y[4], yy[4];

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tk;
	scanf("%d\n", &tk);
	for(int tc = 1; tc <= tk; ++tc) {
		printf("Case #%d: ", tc);

		forn(j, 3)
			cin >> x[j+1] >> y[j+1];

		forn(j, 3)
			cin >> xx[j+1] >> yy[j+1];

		int64 a1 = x[1] - xx[1] - x[3] + xx[3], 
			b1 = x[2] - xx[2] - x[3] + xx[3],
			c1 = xx[3] - x[3];

		int64 a2 = y[1] - yy[1] - y[3] + yy[3], 
			b2 = y[2] - yy[2] - y[3] + yy[3],
			c2 = yy[3] - y[3];

		int64 d = a1 * b2 - b1 * a2;
		int64 d1 = c1 * b2 - b1 * c2;
		int64 d2 = a1 * c2 - c1 * a2;
		if (d == 0) {
			if (d1 != 0 || d2 != 0) {
				puts("No Solution");
			} else {
				double xa = (double)x[1];
				double ya = (double)y[1];
				printf("%.8lf %.8lf\n", xa, ya);
			}
		} else {
			double t1 = double(d1) / d;
			double t2 = double(d2) / d;
			if (t1 > -EPS && t1 + t2 < 1 + EPS &&  t2 > -EPS) {
				double xa = x[1] * t1 + x[2] * t2 + x[3] * (1 - t1 - t2);
				double ya = y[1] * t1 + y[2] * t2 + y[3] * (1 - t1 - t2);
				printf("%.8lf %.8lf\n", xa, ya);
			} else {
				puts("No Solution");
			}
		}
	}

	return 0;
}