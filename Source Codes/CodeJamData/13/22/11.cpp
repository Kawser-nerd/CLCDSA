#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

static const int MAXL = 1024;

int n, x, y;

double res[2*MAXL][2*MAXL];

double Solve() {
	int level = (abs(x) + y) / 2;

	int64 lessCnt = level * (2LL*level-1);
	if (n < lessCnt) return 0.0;
	n -= lessCnt;

	if (n >= 4*level+1)
		return 1.0;

	int maxh = 2*level;
	assert(maxh < 2*MAXL);

	memset(res, 0, sizeof(res));
	res[0][0] = 1.0;
	double ans = 0.0;
	for (int s = 0; s<=2*maxh; s++) {
		for (int a = 0; a<=s; a++) {
			int b = s-a;     
			if (a > maxh || b > maxh) continue;

			if (s == n && a > y)
				ans += res[a][b];

			if (a == maxh && b == maxh) continue;

			if (a == maxh)
				res[a][b+1] += res[a][b];
			else if (b == maxh)
				res[a+1][b] += res[a][b];
			else {
				res[a+1][b] += res[a][b] * 0.5;
				res[a][b+1] += res[a][b] * 0.5;
			}
		}

		if (s == n) return ans;
	}

	assert(0);
	return 0.0;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {

		scanf("%d%d%d", &n, &x, &y);
		double ans = Solve();

		printf("Case #%d: %0.15lf\n", tt, ans);
		fflush(stdout);
	}
	return 0;
}
