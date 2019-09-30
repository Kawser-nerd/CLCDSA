#pragma comment(linker, "/STACK:64000000")
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> pii;

const int dir[6][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {1, -1}, {-1, 1}};//, {1, 1}, {-1, -1}};

int k;
pii arr[1<<20];
map<pii, int> cells;

int mins;
int maxx, maxy;

bool used[1<<20];
void DFS(int u) {
	used[u] = true;

	pii p = arr[u];
	int sum = p.first + p.second;
	if (mins > sum) mins = sum;
	if (maxx < p.first) maxx = p.first;
	if (maxy < p.second) maxy = p.second;

	for (int d = 0; d<6; d++) {
		pii np(p.first + dir[d][0], p.second + dir[d][1]);
		if (cells.find(np) == cells.end()) continue;
		int v = cells[np];
		if (!used[v]) DFS(v);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		int r;
		scanf("%d", &r);

		k = 0;
		cells.clear();
		for (int i = 0; i<r; i++) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for (int u = x1; u<=x2; u++)
				for (int v = y1; v<=y2; v++) {
					pii p(u, v);
					if (cells.find(p) != cells.end()) continue;
					cells[p] = k;
					arr[k] = p;
					k++;
				}
		}

		memset(used, 0, sizeof(used));
		int ans = 0;
		for (int i = 0; i<k; i++) if (!used[i]) {
			mins = 1000000000;
			maxx = -1000000000;
			maxy = -1000000000;
			DFS(i);
			int tres = maxx + maxy - mins;
			if (ans < tres) ans = tres;
		}

		printf("Case #%d: %d\n", tt, ans + 1);
	}
	return 0;
}
