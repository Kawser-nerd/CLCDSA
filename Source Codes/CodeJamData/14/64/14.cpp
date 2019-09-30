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

const int maxN = 1100;
int n, a;

string s[maxN];

void read_data(int test) {
}

void solve(int test) {
	cin >> n >> a;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	vector < int > order(n);
	for (int i = 0; i < n; ++i) {
		order[i] = i;
	}
	do {
		int current = order[0];
		for (int i = 1; i < n; ++i) {
			int x = order[i];
			if (s[current][x] == 'N') {
				current = x;
			}
		}
		if (current == a) {
			printf("Case #%d:", test);
			for (int i = 0; i < n; ++i) {
				printf(" %d", order[i]);
			}
			printf("\n");
			return;
		}
	} while (next_permutation(order.begin(), order.end()));
	printf("Case #%d: IMPOSSIBLE\n", test);
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