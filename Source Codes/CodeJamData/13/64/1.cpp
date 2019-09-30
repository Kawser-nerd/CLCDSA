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

int res, u, v;
int n, k, d;
vector < vector < int > > a;

void check(int start, int current, int x, int y, int z) {
	for (int j = current; j < n; ++j) {
		bool nice = false;
		for (int i = 0; i < d; ++i) {
			if (a[j][i] == x || a[j][i] == y || a[j][i] == z) {
				nice = true;
				break;
			}
		}

		if (!nice) {
			break;
		}

		if (j - start + 1 > res) {
			res = j - start + 1;
			u = start;
			v = j;
		}
	}
}

void check(int start, int current, int x, int y) {
	for (int j = current; j < n; ++j) {
		bool nice = false;
		for (int i = 0; i < d; ++i) {
			if (a[j][i] == x || a[j][i] == y) {
				nice = true;
				break;
			}
		}

		if (!nice) {
			if (k == 3) {
				for (int i = 0; i < d; ++i) {
					check(start, j, x, y, a[j][i]);
				}
			}
			break;
		}

		if (j - start + 1 > res) {
			res = j - start + 1;
			u = start;
			v = j;
		}
	}
}

void check(int current, int start, int position) {
	if (start + res - 1 >= n) {
		return ;
	}

	for (int i = current; i < n; ++i) {
		bool nice = false;
		for (int j = 0; j < d; ++j) {
			if (a[i][j] == a[start][position]) {
				nice = true;
				break;
			}
		}

		if (!nice) {
			for (int j = 0; j < d; ++j) {
				check(start, i, a[start][position], a[i][j]);
			}
			return ;
		}

		if (i - start + 1 > res) {
			res = i - start + 1;
			u = start;
			v = i;
		}
	}
}

void solve(int test) {
	cin >> n >> d >> k;
	a.assign(n, vector < int > (d, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < d; ++j) {
			cin >> a[i][j];
		}
		sort(a[i].begin(), a[i].end());
	}

	res = min(n, k);
	u = 0;
	v = min(n - 1, k - 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < d; ++j) {
			check(i, i, j);
		}
	}

	printf("Case #%d: %d %d\n", test, u, v);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int test = 0; test < tests; ++test) {
		solve(test + 1);
		cerr << test << endl;
		cerr << "Current time: " << clock() << endl;
	}

	cerr << "Time: " << clock() << endl;
	return 0;
}
