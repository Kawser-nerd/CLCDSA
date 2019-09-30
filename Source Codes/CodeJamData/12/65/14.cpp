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

const int maxN = 110;
int n, l[maxN], r[maxN], d[maxN];

void solve(int test) {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &l[i], &r[i]);
	}

	for (int i = 1; i <= n; ++i) {
		d[i] = 0;
	}

	int current = 1;
	for (int i = 1; i <= 10000000; ++i) {
		d[current] = 1 - d[current];
		if (d[current]) {
			current = l[current]; 
		} else {
			current = r[current];
		}

		if (current == n) {
			printf("Case #%d: %d\n", test, i);
			return ;
		}
	}

	printf("Case #%d: Infinity\n", test);
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