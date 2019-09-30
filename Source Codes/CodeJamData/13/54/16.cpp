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

string s;
const int maxN = 20;
double p[1 << maxN];

void solve(int test) {
	cin >> s;
	int n = s.size();
	int mask = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] != '.') {
			mask += (1 << i);
		}
	}

	for (int i = 0; i < (1 << n); ++i) {
		p[i] = 0.0;
	}

	p[mask] = 1.0;
	double res = 0.0;
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			int waiting_time = 0;
			int last = j - 1;
			for (int k = j; k < j + n; ++k) {
				if (i & (1 << (k % n))) {
					++waiting_time;
					last = k;
				} else {
					break;
				}
			}

			if (waiting_time != n) {
				res += (double)(1.0) / (double)(n) * (double)(n - waiting_time) * p[i];
				p[i | (1 << ((last + 1) % n))] += (double)(1.0) / (double)(n) * p[i];
			}
		}
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