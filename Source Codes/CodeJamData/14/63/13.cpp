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

struct pt {
	long long x, y;
	pt() {
	}
	pt(long long x, long long y) : x(x), y(y) {
	}
};

inline int area(pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool intersect_1(int a, int b, int c, int d) {
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	return max(a, c) <= min(b, d);
}

bool intersect(pt a, pt b, pt c, pt d) {
	return intersect_1(a.x, b.x, c.x, d.x)
		&& intersect_1(a.y, b.y, c.y, d.y)
		&& area(a, b, c) * area(a, b, d) <= 0
		&& area(c, d, a) * area(c, d, b) <= 0;
}

void read_data(int test) {
}

const int maxN = 20;
string color[maxN];
int g[maxN][maxN];
int n;
int bits[1 << maxN];

bool check(vector < int >& a, vector < int >& b, vector < int >& c) {
	for (int i = 0; i < a.size(); ++i) {
		if (color[a[i]] != color[b[i]]) {
			return false;
		}
	}

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			if (i != j && g[a[i]][b[j]]) {
				return false;
			}
		}
	}

	for (int i = 0; i < a.size(); ++i) {
		for (int j = i + 1; j < a.size(); ++j) {
			if (g[a[i]][a[j]] != g[b[i]][b[j]]) {
				return false;
			}
		}
	}

	for (int i = 0; i < c.size(); ++i) {
		for (int j = 0; j < a.size(); ++j) {
			if (g[c[i]][a[j]] != g[c[i]][b[j]]) {
				return false;
			}
		}
	}

	for (int i = 0; i < c.size(); ++i) {
		int cnt = 0;
		for (int j = 0; j < c.size(); ++j) {
			if (i != j && g[c[i]][c[j]]) {
				++cnt;
			}
		}
		if (cnt > 2) {
			return false;
		}
	}

	return true;
}

bool check(int maskA, int maskB) {
	vector < int > a, b, c;
	for (int k = 0; k < n; ++k) {
		if (maskA & (1 << k)) {
			a.push_back(k);
		} else if (maskB & (1 << k)) {
			b.push_back(k);
		} else {
			c.push_back(k);
		}
	}

	do {
		if (check(a, b, c)) {
			return true;
		}
	} while (next_permutation(b.begin(), b.end()));
	return false;
}

void solve(int test) {
	memset(g, 0, sizeof(g));
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> color[i];
	}

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		g[u][v] = g[v][u] = 1;
	}

	for (int i = 0; i < (1 << n); ++i) {
		bits[i] = 0;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				++bits[i];
			}
		}
	}

	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			if ((i & j) || bits[i] != bits[j]) {
				continue;
			}

			if (check(i, j)) {
				printf("Case #%d: SYMMETRIC\n", test);
				return;
			}

			
		}
	}

	printf("Case #%d: NOT SYMMETRIC\n", test);
}

int main(int argc, char* argv[]) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

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