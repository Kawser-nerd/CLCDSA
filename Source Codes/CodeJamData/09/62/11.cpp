#include <stdio.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <queue>
#include <utility>
#include <string.h>
#include <string>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef complex<double> tComp;

const double EPS = 1e-9;

long long x[10000], y[10000];

LL sqr(LL a) {
	return a*a;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("usage: %s <input_file>\n", argv[0]);
		return 1;
	}
	freopen(argv[1], "r", stdin);
	int tc;
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen) {
		printf("Case #%d: ", scen);
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			scanf("%lld %lld", &x[i], &y[i]);
		double best = 1e20;
		for (int i=0; i<n; ++i) {
			long long d1 = 1LL<<62;
			long long d2 = 1LL<<62;
			int bi, bj;
			for (int j=0; j<n; ++j) {
				if (i == j)
					continue;
				LL dist = sqr(x[j] - x[i]) + sqr(y[j] - y[i]);
				if (dist < d1) {
					d2 = d1;
					bj = bi;
					d1 = dist;
					bi = j;
				}
				else if (dist < d2) {
					d2 = dist;
					bj = j;
				}
			}
			best = min(best, sqrt(d1) + sqrt(d2) + sqrt(sqr(x[bi]-x[bj]) + sqr(y[bi]-y[bj])));
		}
		printf("%.9lf\n", best);
	}
	return 0;
}
