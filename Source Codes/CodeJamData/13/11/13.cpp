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

bool check(long long r, long long t, long long k) {
	long long x = 2 * r + 2 * k + 1;
	if (x > (t + k) / (k + 1)) {
		return false;
	}

	return x * (k + 1) <= t;
}

const long long inf = 1000000000000000000LL;

void solve(int test) {
	long long r, t;
	cin >> r >> t;
	
	long long left_bound = 0, right_bound = inf;
	while (right_bound - left_bound > 1) {
		long long middle = (left_bound + right_bound) / 2LL;
		if (check(r, t, middle)) {
			left_bound = middle;
		} else {
			right_bound = middle;
		}
	}

	long long res = -1;
	if (check(r, t, left_bound)) {
		res = left_bound;
	}
	if (check(r, t, right_bound)) {
		res = right_bound;
	}

	cout << "Case #" << test << ": " << res + 1 << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d\n", &tests);
	for (int i = 1; i <= tests; ++i) {
		solve(i);
	}
	return 0;
}