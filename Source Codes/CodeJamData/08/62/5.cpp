#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 1000000000;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int n, m, x, y;
int map[5][5];
int ans;

inline bool valid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

inline void sub(int &x, int y) {
	x -= y;
	if (x < 0) x = 0;
}

void attack(int z)
{
	int i, j, k, l;
	int newmap[5][5];
	memcpy(newmap, map, sizeof(newmap));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			if (i == x && j == y) {
				if (z >= 0)
					sub(newmap[x + dx[z]][y + dy[z]], map[x][y]);
			} else {
				l = 0;
				for (k = 0; k < 4; k++)
					if (valid(i + dx[k], j + dy[k])) l = max(l, map[i + dx[k]][j + dy[k]]);
				for (k = 0; k < 4; k++)
					if (valid(i + dx[k], j + dy[k]) && map[i + dx[k]][j + dy[k]] == l) {
						sub(newmap[i + dx[k]][j + dy[k]], map[i][j]);
						break;
					}
			}
		}
	memcpy(map, newmap, sizeof(map));
}

void search(int now)
{
	if (ans == inf || !map[x][y]) return;
	ans = max(ans, now);
	int i;
	for (i = 0; i < 4; i++)
		if (valid(x + dx[i], y + dy[i]) && map[x + dx[i]][y + dy[i]]) break;
	if (i == 4) {
		ans = inf;
		return;
	}
	int prev[5][5];
	memcpy(prev, map, sizeof(prev));
	attack(-1);
	search(now + 1);
	for (i = 0; i < 4; i++) {
		if (valid(x + dx[i], y + dy[i])) {
			memcpy(map, prev, sizeof(map));
			attack(i);
			search(now + 1);
		}
	}
}

int main()
{
	freopen("bsmall.in", "r", stdin);
	freopen("bsmall.out", "w", stdout);

	int i, j, k, z, testcase;

	scanf("%d", &testcase);
	for (z = 1; z <= testcase; z++) {
		scanf("%d%d%d%d", &m, &n, &y, &x);
		x--, y--;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				scanf("%d", &map[i][j]);
		ans = 0;
		search(0);
		printf("Case #%d: ", z);
		if (ans == inf) printf("forever\n");
		else printf("%d day(s)\n", ans);
	}

	return 0;
}
