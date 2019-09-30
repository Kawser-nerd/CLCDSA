#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int i, j;
int d[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int a[100][100];
int g[100][100][4];

char flag[100][100];
char map[100][100];

void dfs(int x, int y, char c) {
	if (flag[x][y]) return;
	int i;
	flag[x][y] = 1;
	map[x][y] = c;
	for (i = 0; i < 4; i++) if (g[x][y][i]) {
		dfs(x + d[i][0], y + d[i][1], c);
	}
}

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int i, j, k, n, m, tx, ty, T, mini, dir, ttx, tty;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		printf("Case #%d:\n", t);
		scanf("%d%d",&n,&m);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				scanf("%d",&a[i][j]);
			}
		}
		memset(g, 0, sizeof(g));
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				mini = a[i][j];
				dir = -1;
				for (k = 0; k < 4; k++) {
					tx = i + d[k][0];
					ty = j + d[k][1];
					if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
					if (a[tx][ty] < mini) mini = a[tx][ty], dir = k, ttx = tx, tty = ty;
				}
				if (dir >= 0) g[i][j][dir] = g[ttx][tty][3 - dir] = 1;
			}
		}
		memset(flag, 0, sizeof(flag));
		k = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) if (!flag[i][j]) {
				dfs(i, j, 'a' + k);
				k++;
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				printf("%c", map[i][j]);
				if (j < m - 1) printf(" ");
			}
			printf("\n");
		}
	}

	return 0;
}
