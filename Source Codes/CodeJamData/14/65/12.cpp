#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
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

void read_data(int test) {
}

const long long inf = 1000000000000000000LL;

map < long long, long long > M;
map < long long, long long > P;
long long n, a, b;

long long calcT(long long n, long long a, long long b) {
	if (M.count(n)) {
		return M[n];
	}

	if (n == 1) {
		return M[n] = 0;
	}

	if (n == 2) {
		return M[n] = a;
	}

	long long res = inf;
	for (int i = 1; i < n; ++i) {
		long long cur = max(a + calcT(n - i, a, b), b + calcT(i, a, b));
		if (cur <= res) {
			res = cur;
			P[n] = i;
		}
	}
	return M[n] = res;
}

long long cleverCalc(long long n, long long a, long long b) {
	vector < long long > lt, rt, value;
	lt.push_back(1);
	rt.push_back(1);
	value.push_back(a - b);

	if (n == 1) {
		return 0;
	}

	lt.push_back(2);
	rt.push_back(2);
	value.push_back(a);

	if (n == 2) {
		return a;
	}

	while (true) {
		if (rt.back() >= n) {
			return value.back();
		}

		long long bound = value.back();

	start:
		long long best = inf;

		for (int i = 0; i < lt.size(); ++i) {
			if (b + value[i] > best) {
				break;
			}
			for (int j = i; j < lt.size(); ++j) {
				if (a + value[j] > best) {
					break;
				}
				long long cur = max(b + value[i], a + value[j]);
				if (cur > bound) {
					best = min(best, cur);
				}
			}
		}

		long long nl = rt.back() + 1;
		long long nr = -1;

		for (int i = 0; i < lt.size(); ++i) {
			if (value[i] + b > best) {
				break;
			}
			for (int j = i; j < lt.size(); ++j) {
				if (value[j] + a > best) {
					break;
				}

				long long cur = max(value[i] + b, value[j] + a);
				long long nbound = rt[i] + rt[j];
				if (cur > bound) {
					nr = max(nr, nbound);
				}
			}
		}

		if (nr == -1) {
			bound = best;
			goto start;
		}

		lt.push_back(nl);
		rt.push_back(nr);
		value.push_back(best);
	}
}

void solve(int test) {
	M.clear();
	cin >> n >> a >> b;
	/*for (int i = 1; i <= n; ++i) {
		if (i % 100 == 0) {
			cerr << test << ": " << i << endl;
		}
		if (calcT(i, a, b) != cleverCalc(i, a, b)) {
			cerr << "BAD!!!" << endl;
			cout << i << " " << a << " " << b << endl;
			cout << calcT(i, a, b) << endl;
			cout << cleverCalc(i, a, b) << endl;
			exit(0);
		}
	}*/
	//cout << calcT(n, a, b) << endl;
	long long res = cleverCalc(n, a, b);
	if (n == 1) {
		res = 0;
	}
	cout << "Case #" << test << ": " << res << endl;
}

int main(int argc, char* argv[]) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	/*for (int n = 2; n <= 1000; ++n) {
		cerr << n << endl;
		for (int a = 1; a <= 20; ++a) {
			for (int b = a; b <= 20; ++b) {
				M.clear();
				if (calcT(n, a, b) != cleverCalc(n, a, b)) {
					cerr << "BAD!!!" << endl;
					cout << n << " " << a << " " << b << endl;
					cout << calcT(n, a, b) << endl;
					cout << cleverCalc(n, a, b) << endl;
					exit(0);
				}
			}
		}
	}*/

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
		}
		else {
			read_data(i);
		}
	}
	return 0;
}