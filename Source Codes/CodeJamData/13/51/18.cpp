#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 50;
long long B;
int n;
long long x[maxN];

long long getNeed(int i, long long middle) {
	long long need = 0;
	for (int k = 0; k < i; ++k) {
		need += middle - x[k];
	}

	for (int k = i; k < n; ++k) {
		if (x[k] < middle + 1) {
			need += middle + 1 - x[k];
		}
	}
	return need;
}

void solve(int test) {
	cin >> B >> n;
	memset(x, 0, sizeof(x));
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}

	n = 37;
	sort(x, x + n);
	double res = 0.0;

	for (int i = 1; i <= n; ++i) {
		long long needs = 0;
		for (int j = 0; j < i; ++j) {
			needs += x[i - 1] - x[j];
		}
		for (int j = i; j < n; ++j) {
			if (x[j] < x[i - 1] + 1) {
				needs += x[i - 1] + 1LL - x[j];
			}
		}

		if (needs > B) {
			continue;
		}

		long long left_bound = x[i - 1], right_bound = 1000000000000000LL;
		long long spend = 0;
		while (right_bound - left_bound > 1) {
			long long middle = (left_bound + right_bound) / 2;

			if (getNeed(i, middle) <= B) {
				left_bound = middle;
			} else {
				right_bound = middle;
			}
		}

		long long bound = 0;
		if (getNeed(i, right_bound) <= B) {
			spend = getNeed(i, right_bound);
			bound = right_bound;
		} else if (getNeed(i, left_bound) <= B) {
			spend = getNeed(i, left_bound);
			bound = left_bound;
		} else {
			continue;
		}

		double score = 0.0;
		for (int j = 0; j < i; ++j) {
			score += (double)(1.0) / (double)(i) * (double)(bound - x[j]) * 36.0;
		}
		res = max(res, (score - spend));
	}
	printf("Case #%d: %.10lf\n", test, res);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d\n", &tests);
	for (int i = 1; i <= tests; ++i) {
		solve(i);
		cerr << i << endl;
	}

	return 0;
}