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

const int maxN = 2000;
int n, x[maxN], y[maxN], color[maxN];
char code;

inline int ab(int x) {
	return x > 0 ? x : -x;
}

bool comp(pair < int, int > A, pair < int, int > B) {
	return make_pair(ab(A.first) + ab(A.second), make_pair(- A.first, - A.second)) < make_pair(ab(B.first) + ab(B.second), make_pair(- B.first, - B.second));
}

void solve(int test) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		scanf("  %c", &code);
		if (code == '.') {
			color[i] = 0;
		} else {
			color[i] = 1;
		}
	}

	vector < pair < int, int > > ways;

	const int bound = 1000;
	for (int i = -bound; i <= bound; ++i) {
		for (int j = -bound; j <= bound; ++j) {
			bool good = true;
			for (int k = 0; k < n; ++k) {
				int dist = max(ab(x[k] - i), ab(y[k] - j));
				if ((dist & 1) && color[k] == 0) {
					good = false;
					break;
				}
				if ((dist & 1) == 0 && color[k] == 1) {
					good = false;
					break;
				}
			}
			if (good) {
				ways.push_back(make_pair(i, j));
			}
		}
	}

	if (ways.size() == 0) {
		printf("Case #%d: Too damaged\n", test);
	} else {
		pair < int, int > best = ways[0];
		for (int i = 0; i < ways.size(); ++i) {
			if (comp(ways[i], best)) {
				best = ways[i];
			}
		}
		printf("Case #%d: %d %d\n", test, best.first, best.second);
	}
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