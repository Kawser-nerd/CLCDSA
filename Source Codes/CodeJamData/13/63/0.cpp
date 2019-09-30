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

vector < pair < double, double > > res;
vector < double > x, y;
int n;

const double eps = 1e-9;

void check(double A, double B, double C) {
	if (res.size() != 0) {
		return ;
	}

	vector < pair < double, double > > p(n);
	double D = sqrt(A * A + B * B);
	double dx = A / D;
	double dy = B / D;
	for (int i = 0; i < n; ++i) {
		double h = A * x[i] + B * y[i] + C;
		h /= D;
		p[i].first = x[i] - h * dx;
		p[i].second = y[i] - h * dy;
	}

	sort(p.begin(), p.end());

	double cx = (p[n / 2 - 1].first + p[n / 2].first) / 2.0;
	double cy = (p[n / 2 - 1].second + p[n / 2].second) / 2.0;

	double A2 = -B;
	double B2 = A;

	double C2 = - (A2 * cx + B2 * cy);

	int a = 0, b = 0, c = 0, d = 0;

	for (int i = 0; i < n; ++i) {
		double p = A * x[i] + B * y[i] + C;
		double q = A2 * x[i] + B2 * y[i] + C2;

		if (p > eps && q > eps) {
			++a;
		}
		if (p > eps && q < -eps) {
			++b;
		}
		if (p < -eps && q > eps) {
			++c;
		}
		if (p < -eps && q < -eps) {
			++d;
		}
	}

	if (a == n / 4 && b == n / 4 && c == n / 4 && d == n / 4) {
		res.push_back(make_pair(cx, cy));
		res.push_back(make_pair(cx + A2, cy + B2));
	}
}

void solve(double A, double B, double C) {
	check(A, B, C + max(1.0, fabs(C)) * 1e-6);
	check(A, B, C - max(1.0, fabs(C)) * 1e-6);

	check(A, B + max(1.0, fabs(B)) * 1e-6, C);
	check(A, B - max(1.0, fabs(B)) * 1e-6, C);

	check(A + max(1.0, fabs(A)) * 1e-6, B, C);
	check(A - max(1.0, fabs(A)) * 1e-6, B, C);
}

void solve(int test) {
	cin >> n;
	n *= 4;
	vector < int > x(n), y(n);
	::x.resize(n);
	::y.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		::x[i] = x[i];
		::y[i] = y[i];
	}

	res.clear();
	for (int i = 0; i < n && res.size() == 0; ++i) {
		for (int j = i + 1; j < n && res.size() == 0; ++j) {
			long long A = y[i] - y[j];
			long long B = x[j] - x[i];
			long long C = (long long)(x[i]) * (long long)(y[j]) - (long long)(x[j]) * (long long)(y[i]);

			solve(A, B, C);
		}
	}

	if (res.size() == 0) {
		printf("Case #%d: IMPOSSIBLE\n", test);
	} else {
		printf("Case #%d: %.9lf %.9lf %.9lf %.9lf\n", test, res[0].first, res[0].second, res[1].first, res[1].second);
	}
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
