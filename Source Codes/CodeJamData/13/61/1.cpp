#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

void solve(int test) {
	int c, x, n;
	cin >> c;
	cin >> x >> n;
	vector < int > s(c), e(c), t(c), len(c);
	for (int i = 0; i < c; ++i) {
		cin >> s[i] >> e[i] >> t[i];
		--s[i];
		--e[i];
		len[i] = e[i] - s[i];
		if (len[i] < 0) {
			len[i] += n;
		}
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int p = 0; p <= x; ++p) {
			for (int length = 1; length <= x; ++length) {
				bool nice = true;
				if (p + length > x) {
					nice = false;
					continue;
				}

				for (int j = 0; j < c && nice; ++j) {
					for (int k = p + p; k <= 2 * (p + length) && nice; ++k) {
						int position = (2 * i - k + (p + p)) % (n + n);
						if (position < 0) {
							position += (n + n);
						}
						if (k >= t[j] * 2 && k <= (t[j] + len[j]) * 2) {
							int current = (2 * s[j] + (k - 2 * t[j])) % (n + n);
							if (position == current) {
								nice = false;
							}
						}
					}
				}
				if (nice) {
					res = max(res, length);
				}
			}
		}
	}

	printf("Case #%d: %d\n", test, res);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int test = 0; test < tests; ++test) {
		solve(test + 1);
		cerr << test << endl;
	}

	cerr << "Time: " << clock() << endl;
	return 0;
}
