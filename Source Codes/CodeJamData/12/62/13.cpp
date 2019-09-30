#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 11000;
int n, k;
int c[maxN], a[maxN], b[maxN];

struct rat {
	long long a, b;
	rat() {
		a = 0;
		b = 1;
	}
	rat(long long a, long long b) : a(a), b(b) {
	}

	bool operator < (const rat &other) const {
		return a * other.b < other.a * b;
	}

	double value() const {
		return (double)(a) / (double)(b);
	}
};

vector < rat > have;

double calculate(const vector < int > &ind) {
	double A = 1.0, B = 1.0;
	for (int i = 0; i < k; ++i) {
		A = A * (1.0 - have[ind[i]].value()) + B * have[ind[i]].value();
		B *= have[ind[i]].value();
	}
	return 1.0 - A;
}

void solve(int test) {
	scanf("%d%d", &n, &k);
	have.clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%d/%d%d", &a[i], &b[i], &c[i]);
		for (int j = 0; j < c[i]; ++j) {
			have.push_back(rat(a[i], b[i]));
		}
	}

	sort(have.begin(), have.end());
	reverse(have.begin(), have.end());

	vector < int > answer;
	for (int i = 0; i < k; ++i) {
		answer.push_back(i);
	}
	double res = calculate(answer);
	const double eps = 1e-9;
	for (int i = k - 1; i >= 0; --i) {
		int bound = have.size() - 1;
		if (i != k - 1) {
			bound = min(bound, answer[i + 1] - 1);
		}

		for (int j = answer[i]; j <= bound; ++j) {
			int old = answer[i];
			answer[i] = j;
			double cur = calculate(answer);
			if (cur < res + eps) {
				res = cur;
			} else {
				answer[i] = old;
				break;
			}
		}
	}

	printf("Case #%d: %.10lf\n", test, res);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
		cerr << i << endl;
	}
	cerr << clock() << endl;
	return 0;
}