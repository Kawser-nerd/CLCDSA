#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
int n, l[maxN], p[maxN], order[maxN];

bool comp(int x, int y) {
	int A = 100 * l[x] + (100 - p[x]) * l[y];
	int B = 100 * l[y] + (100 - p[y]) * l[x];

	return make_pair(A, x) < make_pair(B, y);
}

void solve(int test) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &l[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		order[i] = i;
	}
	sort(order, order + n, comp);
	printf("Case #%d:", test);
	for (int i = 0; i < n; ++i) {
		printf(" %d", order[i]);
	}
	printf("\n");
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
	return 0;
}