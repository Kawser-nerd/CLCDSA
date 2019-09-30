#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 5000;
double d[maxN][maxN];

double solve(int n, int x, int y) {
	int m = 1;
	for (int i = 1; ; ++i) {
		if (i * (2 * i - 1) <= n) {
			m = i;
		} else {
			break;
		}
	}

	if (x - y >= - (2 * m - 1) && x + y <= 2 * m - 1) {
		return 1.0;
	}

	if (x - y < - (2 * m + 1) || x + y > 2 * m + 1) {
		return 0.0;
	}

	n = n - m * (2 * m - 1);
	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			d[i][j] = 0.0;
		}
	}

	cerr << 2 * m << endl;
	d[0][0] = 1.0;
	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			if (i < 2 * m && j < 2 * m) {
				d[i + 1][j] += d[i][j] / 2.0;
				d[i][j + 1] += d[i][j] / 2.0;
			} else if (i == 2 * m && j < 2 * m) {
				d[i][j + 1] += d[i][j];
			} else if (i < 2 * m && j == 2 * m) {
				d[i + 1][j] += d[i][j];
			}
		}
	}

	double res = 0.0;
	for (int i = y + 1; i <= 2 * m; ++i) {
		if (n - i >= 0) {
			res += d[i][n - i];
		}
	}
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		cout << "Case #" << test << ": ";
		int n, x, y;
		cin >> n >> x >> y;
		printf("%.10lf\n", solve(n, x, y));
		cerr << ": " << test << endl;
	}
	return 0;
}