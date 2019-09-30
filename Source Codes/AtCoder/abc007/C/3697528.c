#include<stdio.h>
char go, stop, Goal, Start;
int memo2 = -1;
int stx, sty, gox, goy;
//????
int check(int x, int y, int memo, int n, int m);
char map[1000][1000];
//????????
int not_map[1000][1000] = {};
//???????????????
int turn[1000][1000] = {};
//?????????????
int task[1000000][2] = {};
//????
int start(int n, int m) {
	int memo = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[j][i] == Start) {
				turn[j][i] = 0;
				if (i != 1) { turn[i - 1][j] = 1; }
				if (i != n) { turn[i + 1][j] = 1; }
				if (i != 1) { turn[i][j - 1] = 1; }
				if (i != m) { turn[i][j + 1] = 1; }
				return check(j, i, memo, n, m);
			}
		}
	}
}

//???????
int map_turn(int x, int y, int n, int m) {
	if (x != 1 && turn[x - 1][y] == 0) { turn[x - 1][y] = turn[x][y] + 1; }
	if (x != n && turn[x + 1][y] == 0) { turn[x + 1][y] = turn[x][y] + 1; }
	if (y != 1 && turn[x][y - 1] == 0) { turn[x][y - 1] = turn[x][y] + 1; }
	if (y != m && turn[x][y + 1] == 0) { turn[x][y + 1] = turn[x][y] + 1; }
}

//?????????
int check(int x, int y, int memo, int n, int m) {
	if (map[x][y] == Goal) { return turn[gox][goy]; }
	if (map[x][y] == stop) {
		memo2++;
		check(task[memo2][0], task[memo2][1], memo, n, m);
	}
	map_turn(x, y, n, m);


	if (x != 1 && map[x - 1][y] != stop && not_map[x - 1][y] != 1) {
		task[memo][0] = x - 1;
		task[memo][1] = y;
		memo++;
		not_map[x - 1][y] = 1;
	}
	if (x != n && map[x + 1][y] != stop && not_map[x + 1][y] != 1) {
		task[memo][0] = x + 1;
		task[memo][1] = y;
		memo++;
		not_map[x + 1][y] = 1;
	}
	if (y != 1 && map[x][y - 1] != stop && not_map[x][y - 1] != 1) {
		task[memo][0] = x;
		task[memo][1] = y - 1;
		memo++;
		not_map[x][y - 1] = 1;
	}
	if (y != m && map[x][y + 1] != stop && not_map[x][y + 1] != 1) {
		task[memo][0] = x;
		task[memo][1] = y + 1;
		memo++;
		not_map[x][y + 1] = 1;
	}
	memo2++;

	return check(task[memo2][0], task[memo2][1], memo, n, m);
}

int main() {
	int n, m;
	go = '.';
	stop = '#';
	Start = 'S';
	Goal = 'G';
	scanf("%d%d", &m, &n);
	scanf("%d%d%d%d", &sty, &stx, &goy, &gox);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &map[j][i]);
		}
	}
	map[stx][sty] = 'S';
	map[gox][goy] = 'G';
	printf("%d\n", start(n, m));
} ./Main.c: In function ‘main’:
./Main.c:84:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &m, &n);
  ^
./Main.c:85:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &sty, &stx, &goy, &gox);
  ^
./Main.c:88:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf(" %c", &map[j][i]);
    ^