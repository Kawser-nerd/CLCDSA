#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>

using namespace std;

const int maxN = 210;
int n, a[maxN];

void solve(int test) {
	scanf("%d", &n);
	int s = 0;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), s += a[i];

	printf("Case #%d:", test + 1);
	for (int i = 1; i <= n; ++i) {
		double l = 0.0, r = 1.0;
		int iters = 0;
		while (iters < 200) {
			++iters;
			double key = (l + r) / 2.0;

			double score = (double)(a[i]) + key * (double)(s);
			double need = 0.0;
			for (int j = 1; j <= n; ++j)
				if (i != j) {
					if ((double)(a[j]) < score) need += score - (double)(a[j]);
				}

			if (need + key * (double)(s) <= (double)(s)) {
				l = key;
			} else {
				r = key;
			}
		}
		printf(" %.10lf", (l + r) * 50.0);
	}
	printf("\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i);
	}
	return 0;
}