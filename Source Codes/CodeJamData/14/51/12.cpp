#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100000;
const long long inf = 1000000000000000000LL;
long long n, p, q, r, s;
long long a[maxN], b[maxN];

void read_data(int test) {
}

bool check(long long bound) {
	for (int i = 0; i < n; ++i) {
		long long leftS = 0;
		if (i > 0) {
			leftS = b[i - 1];
		}
		if (leftS > bound) {
			continue;
		}

		int left_bound = i, right_bound = n - 1;
		while (right_bound - left_bound > 1) {
			int middle = (left_bound + right_bound) / 2;
			if (b[middle] - (i == 0 ? 0 : b[i - 1]) <= bound) {
				left_bound = middle;
			} else {
				right_bound = middle;
			}
		}

		for (int j = left_bound; j <= right_bound; ++j) {
			long long middleS = b[j] - (i == 0 ? 0 : b[i - 1]);
			long long rightS = b[n - 1] - leftS - middleS;
			if (leftS <= bound && middleS <= bound && rightS <= bound) {
				return true;
			}
		}
	}
	return false;
}

void solve(int test) {
	cin >> n >> p >> q >> r >> s;
	for (long long i = 0; i < n; ++i) {
		a[i] = ((i * p + q) % r) + s;
		b[i] = a[i];
		if (i > 0) {
			b[i] += b[i - 1];
		}
	}

	long long left_bound = 0, right_bound = inf;
	while (right_bound - left_bound > 1) {
		long long middle = (left_bound + right_bound) / 2;
		if (check(middle)) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}

	long long bound = right_bound;
	if (check(left_bound)) {
		bound = left_bound;
	}

	double res = (double)(b[n - 1] - bound) / (double)(b[n - 1]);
	printf("Case #%d: %.10lf\n", test, res);
}

int main(int argc, char* argv[]) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen(argv[3], "w", stdout);

	int left_bound, right_bound;
	//sscanf(argv[1], "%d", &left_bound);
	//sscanf(argv[2], "%d", &right_bound);

	int tests;
	scanf("%d", &tests);
	left_bound = 1;
	right_bound = tests;
	for (int i = 1; i <= tests; ++i) {
		if (i >= left_bound && i <= right_bound) {
			solve(i);
			cerr << i << ": " << clock() << endl;
		} else {
			read_data(i);
		}
	}
	return 0;
}