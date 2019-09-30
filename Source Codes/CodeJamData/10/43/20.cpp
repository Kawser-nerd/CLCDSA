#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>
#include <cctype>
using namespace std;

typedef long double Real;

const Real o = 1e-8;
const Real pi = acos(-1.0);

const int max_n = 1024;
const int oo = 0x7fffffff;

struct Rect {
	int x1, y1, x2, y2;
};

bool a[max_n][max_n];
Rect r[max_n];
int n;
int q[max_n];
int head, tail;
int ans;
int T, I;
bool visit[max_n];

void BFS(int u) {
	head = 0; tail = 1; q[0] = u; visit[u] = true;
	while (head < tail) {
		int x = q[head];
		for (int y = 0; y < n; y++) {
			if (!visit[y] && a[x][y]) {
				q[tail] = y; tail++;
				visit[y] = true;
			}
		}
		head++;
	}
}

void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &r[i].x1, &r[i].y1, &r[i].x2, &r[i].y2);
	}
}

void solve() {
	memset(a, 0, sizeof a);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (r[i].x2 == r[j].x1 - 1 && r[i].y2 == r[j].y1 - 1 ||
					r[j].x2 == r[i].x1 - 1 && r[j].y2 == r[i].y1 - 1) {
				a[i][j] = false;
				continue;
			}
			if (r[i].x1 <= r[j].x2 + 1 && r[j].x1 <= r[i].x2 + 1 &&
					r[i].y1 <= r[j].y2 + 1 && r[j].y1 <= r[i].y2 + 1) {
				a[i][j] = true;
				continue;
			}
			a[i][j] = false;
		}
	}
	memset(visit, 0, sizeof visit);
	ans = 0;
	for (int u = 0; u < n; u++) {
		if (!visit[u]) {
			BFS(u);
			int min_v = oo, max_x = -1, max_y = -1;
			for (int k = 0; k < tail; k++) {
				int i = q[k];
				min_v = min(min_v, r[i].x1 + r[i].y1);
				max_x = max(max_x, r[i].x2);
				max_y = max(max_y, r[i].y2);
			}
			ans = max(ans, max_x + max_y - min_v + 1);
		}
	}
}

void output() {
	printf("Case #%d: %d\n", I + 1, ans);
}

int main() {
	scanf("%d", &T);
	for (I = 0; I < T; I++) {
		input();
		solve();
		output();
	}
	return 0;
}

