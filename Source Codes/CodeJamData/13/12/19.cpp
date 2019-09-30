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

bool check(long long E, long long R, vector < long long > used, int index, long long value) {
	used[index] += value;
	bool result = true;
	long long current = E;
	for (int i = 0; i < used.size(); ++i) {
		current -= used[i];
		if (current < 0) {
			result = false;
			break;
		}

		current = min(E, current + R);
	}
	used[index] -= value;
	return result;
}

void solve(int test) {
	int E, R, n;
	cin >> E >> R >> n;
	vector < int > v(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	vector < long long > used(n, 0);
	set < pair < int, int > > unfilled;
	for (int i = 0; i < n; ++i) {
		unfilled.insert(make_pair(-v[i], i));
	}

	long long profit = 0;
	while (!unfilled.empty()) {
		int index = unfilled.begin()->second;
		unfilled.erase(unfilled.begin());

		long long left_bound = 0, right_bound = E;
		while (right_bound - left_bound > 1) {
			long long middle = (left_bound + right_bound) / 2;
			if (check(E, R, used, index, middle)) {
				left_bound = middle;
			} else {
				right_bound = middle;
			}
		}

		if (check(E, R, used, index, right_bound)) {
			used[index] += right_bound;
			profit += (long long)(v[index]) * (long long)(right_bound);
		} else {
			used[index] += left_bound;
			profit += (long long)(v[index]) * (long long)(left_bound);
		}
	}

	cout << "Case #" << test << ": " << profit << endl;
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