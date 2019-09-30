#include <iostream>
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

const int maxN = 110;
int p, q, n;
int h[maxN], g[maxN];

int d[110][210][1010][2];

void read_data(int test) {
}

int calc(int killed, int health, int skipped, int move) {
	if (d[killed][health][skipped][move] != -1) {
		return d[killed][health][skipped][move];
	}

	if (killed == n) {
		return d[killed][health][skipped][move] = 0;
	}

	if (move == 1) {
		int res = 0;
		/*for (int i = 0; i <= skipped; ++i) {
			int current = health - i * p;
			if (current <= 0) {
				res = max(res, calc(killed + 1, h[killed + 1], skipped - i, move) + g[killed]);
			} else {
				if (current <= q) {
					res = max(res, calc(killed + 1, h[killed + 1], skipped - i, 1 - move));
				} else {
					res = max(res, calc(killed, current - q, skipped - i, 1 - move));
				}
			}
		}*/
		if (skipped > 0) {
			if (health <= p) {
				res = max(res, calc(killed + 1, h[killed + 1], skipped - 1, move) + g[killed]);
			} else {
				res = max(res, calc(killed, health - p, skipped - 1, move));
			}
		}
		if (health <= q) {
			res = max(res, calc(killed + 1, h[killed + 1], skipped, 1 - move));
		} else {
			res = max(res, calc(killed, health - q, skipped, 1 - move));
		}
		return d[killed][health][skipped][move] = res;
	} else {
		int res = 0;
		res = max(res, calc(killed, health, skipped + 1, 1 - move));
		if (health <= p) {
			res = max(res, calc(killed + 1, h[killed + 1], skipped, 1 - move) + g[killed]);
		} else {
			if (skipped > 0) {
				res = max(res, calc(killed, health - p, skipped - 1, move));
			}
			res = max(res, calc(killed, health - p, skipped, 1 - move));
		}
		/*for (int i = 0; i <= skipped; ++i) {
			int current = health - i * p;
			if (current <= 0) {
				res = max(res, calc(killed + 1, h[killed + 1], skipped - i, 1 - move) + g[killed]);
			} else {
				res = max(res, calc(killed, health - i * p, skipped - i, 1 - move));
			}
		}*/
		return d[killed][health][skipped][move] = res;
	}
}

void solve(int test) {
	cin >> p >> q >> n;
	for (int i = 0; i < n; ++i) {
		cin >> h[i] >> g[i];
	}
	memset(d, -1, sizeof(d));
	printf("Case #%d: %d\n", test, calc(0, h[0], 0, 0));
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
		} else {
			read_data(i);
		}
	}
	return 0;
}