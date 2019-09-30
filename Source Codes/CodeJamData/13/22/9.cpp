#pragma comment(linker, "/STACK:128777216")

#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <functional>
#include <numeric>
#include <sstream>
#include <exception>
#include <cassert>

typedef long long i64;
typedef unsigned int u32;
const int null = 0;

using namespace std;

template<class T> int size(const T &a) {
	return int(a.size());
}
template<class T> T abs(const T &a) {
	return (a < 0? -a: a);
}
template<class T> T sqr(const T &a) {
	return a * a;
}

#define all(a) a.begin(),a.end()

const int max_n = 5000;

double dp[max_n][max_n];

int main() {
#ifdef pperm
	freopen("input.txt", "r", stdin);
	//freopen("input.txt", "w", stdout);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int iTest = 1; iTest <= T; iTest++) {
		printf("Case #%d: ", iTest);
		int n, x, y;
		cin >> n >> x >> y;
		x = abs(x);
		if ((x + y) & 1) {
			printf("0\n");
			continue;
		}
		int w = 0, c = 1;
		for (w = 0; c <= n; c += 4, w += 2) {
			n -= c;
		}
		if (-w < x - y && x + y < w) {
			printf("1\n");
			continue;
		}
		int h = (c - 1) / 2;
		double res = 0;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1.0;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i <= h && i <= k; i++) {
				int j = k - i;
				if (j > h) continue;
				if (dp[i][j] < 1e-200) {
					dp[i][j] = 0;
				}
				if (i == h) {
					dp[i][j + 1] += dp[i][j];
				} else if (j == h) {
					dp[i + 1][j] += dp[i][j];
				} else {
					dp[i + 1][j] += dp[i][j] * 0.5;
					dp[i][j + 1] += dp[i][j] * 0.5;
				}
			}
		}
		for (int i = 0; i <= h; i++) {
			int j = n - i;
			if (-w == x - y && i > y || x + y == w && j > y) {
				res += dp[i][j];
			}
		}
		printf("%.15lf\n", max(min(res, 1.0), 0.0));
	}
#ifdef pperm
	fprintf(stderr, "\n%.3lf\n", clock() / double(CLOCKS_PER_SEC));
#endif
	return 0;
}