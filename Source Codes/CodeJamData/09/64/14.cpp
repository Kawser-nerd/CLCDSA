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

int x[20], y[20], r[20], s[20];

LL sqr(LL a) {
	return a * a;
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
			scanf("%d %d %d %d", &x[i], &y[i], &r[i], &s[i]);
		int N = 1<<n;
		int best = 0;
		for (int m=0; m<N; ++m) {
			bool valid = true;
			int cost = 0;
			for (int i=0; valid && i<n; ++i) {
				if (m & (1<<i)) continue;
				for (int j=0; j<n; ++j)
					if (sqr(x[i]-x[j])+sqr(y[i]-y[j]) <= r[i]*r[i] && (m & (1<<j))) {
						valid = false;
						break;
					}
				cost += s[i];
			}
			if (valid && cost > best)
				best = cost;
		}
		printf("%d\n", best);
	}
	return 0;
}
