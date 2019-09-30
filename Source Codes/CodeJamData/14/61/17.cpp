#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

char buf[2005][2005];

int r[2005];
int c[2005];

void Solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; ++i) {
		scanf("%s", buf[i]);
	}
	int tr1 = 0, tc1 = 0, r1 = 0, c1 = 0, r2 = 0, c2 = 0;
	for (int i = 0; i < 2 * n; ++i) {
		if (buf[i][0] == '0') {
			r[i] = 1;
			++tr1;
			r1 = i;
		} else {
			r[i] = 0;
			r2 = i;
		}

		if (buf[0][i] == '0') {
			c[i] = 1;
			++tc1;
			c1 = i;
		} else {
			c[i] = 0;
			c2 = i;
		}
	}
	if (tr1 != n || tc1 != n) {
		puts("IMPOSSIBLE");
		return;
	}
	bool fail = false;
	for (int i = 0; i < 2 * n; ++i) {
		for (int j = 0; j < 2 * n; ++j) {
			if (r[i] == 1) {
				fail |= buf[i][j] != buf[r1][j];
			} else {
				fail |= buf[i][j] != buf[r2][j];
			}

			if (c[i] == 1) {
				fail |= buf[j][i] != buf[j][c1];
			} else {
				fail |= buf[j][i] != buf[j][c2];
			}
		}
	}
	for (int i = 0; i < 2 * n; ++i) {
		for (int j = 0; j < 2 * n; ++j) {
			if (buf[r1][j] == buf[r2][j] || buf[j][c1] == buf[j][c2]) {
				fail = true;
			}
		}
	}
	if (fail) {
		puts("IMPOSSIBLE");
		return;
	}
	int rv1 = 0, rv2 = 0, cv1 = 0, cv2 = 0;
	for (int i = 0; i < 2 * n; ++i) {
		if (r[i] == 1) {
			if (i & 1) {
				++rv1;
			} else {
				++rv2;
			}
		}
		if (c[i] == 1) {
			if (i & 1) {
				++cv1;
			} else {
				++cv2;
			}
		}
	}
	int ret = min(rv1, rv2) + min(cv1, cv2);
	printf("%d\n", ret);
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T, tc = 0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++tc);
		Solve();
	}    
	return 0;
}