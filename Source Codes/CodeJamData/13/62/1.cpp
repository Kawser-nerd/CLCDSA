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

const double eps = 1e-9;

int getNumber() {
	int n = (rand() * rand() + rand()) % 1000000;
	return n;
}

void gen() {
	int n = 50000;
	printf("%d\n", n);
	vector < int > a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = getNumber();
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int ends = 0;

double solve(vector < double > a) {
	int n = a.size();
	vector < double > x(n);

	double left_bound = 0.0, right_bound = 1000000.0;
	for (int iters = 0; iters < 200; ++iters) {
		double middle = (left_bound + right_bound) / 2.0;

		//cerr << middle << endl;

		bool have_solution = false;

		for (int i = 0; i < n && !have_solution; ++i) {
			for (int j = 0; j < n && !have_solution; ++j) {
				if (i == j) {
					continue;
				}

				x[i] = a[i] - middle;
				x[j] = a[j] + middle;

				double d = (x[j] - x[i]) / (double)(j - i);
				bool nice = true;
				for (int k = 0; k < n; ++k) {
					double p = x[i] + d * (double)(k - i);
					if (p >= a[k] - middle - eps && p <= a[k] + middle + eps) {
						continue;
					}
					nice = false;
					break;
				}
				if (nice) {
					have_solution = true;
				}
			}
		}

		if (have_solution) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}

	return (left_bound + right_bound) / 2.0;
}

void cleverSolve(int test) {
	int n;
	cin >> n;
	vector < double > x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}

	double res = 1e20;
	for (int i = 0; i + 1 < n; ++i) {
		double d = -1.0;
		for (int j = i + 1; j < n; ++j) {
			double v = (x[j] - x[i]) / (double)(j - i);
			if (v > d) {
				d = v;
			}
		}

		bool nice = true;
		for (int j = 0; j < i; ++j) {
			if (x[i] + (double)(j - i) * d < x[j] - eps) {
				nice = false;
				break;
			}
		}

		if (!nice) {
			continue;
		}

		double t = 0.0;
		for (int j = 0; j < n; ++j) {
			t = max(t, (double)(j - i) * d + x[i] - x[j]);
		}
		res = min(res, t / 2.0);
	}

	for (int i = 0; i + 1 < n; ++i) {
		double d = 1e20;
		for (int j = i + 1; j < n; ++j) {
			double v = (x[j] - x[i]) / (double)(j - i);
			if (v < d) {
				d = v;
			}
		}

		bool nice = true;
		for (int j = 0; j < i; ++j) {
			if (x[i] + (double)(j - i) * d > x[j] + eps) {
				nice = false;
				break;
			}
		}

		if (!nice) {
			continue;
		}

		double t = 0.0;
		for (int j = 0; j < n; ++j) {
			t = max(t, - (double)(j - i) * d + x[j] - x[i]);
		}
		res = min(res, t / 2.0);
	}

	printf("Case #%d: %.10lf\n", test, res);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	/*printf("10\n");
	for (int i = 0; i < 10; ++i) {
		gen();
	}*/

	int tests;
	scanf("%d", &tests);
	for (int test = 0; test < tests; ++test) {
		cleverSolve(test + 1);
		cerr << test << endl;
	}

	cerr << "Time: " << clock() << endl;
	return 0;
}
