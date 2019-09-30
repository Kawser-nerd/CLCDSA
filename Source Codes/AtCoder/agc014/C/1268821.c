#include <stdio.h>
#include <math.h>

#define FOR(I, A, B) for(int I = (A); I < (B); I++)

#define N (800)

int H, W, K;
char map[N + 1][N + 1];
int q[N * N][2];

int is_edge(int x, int y) {
	return x == 0 || y == 0 || (H - 1) == x || (W - 1) == y;
}

int min(int x, int y) {
	return x < y ? x : y;
}

int score(int p[2]) {
	int x = p[0];
	int y = p[1];
	return min(min(x, H - 1 - x), min(y, W - 1 - y));
}

void core() {
	int sx = 0, sy = 0;
	scanf("%d%d%d", &H, &W, &K);
	FOR(i, 0, H)
	{
		scanf("%s", map[i]);
		FOR(j, 0, W)
		{
			if (map[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	}
	//
	int l = 0, r = 1;
	q[0][0] = sx;
	q[0][1] = sy;
	FOR(k, 0, K)
	{
		if (l == r) {
			break;
		}
		int d = 0;
		FOR(i, l, r)
		{
			int x = q[i][0];
			int y = q[i][1];
			if (!is_edge(x, y)) {
				if (map[x - 1][y] == '.') {
					q[r + d][0] = x - 1;
					q[r + d][1] = y;
					map[x - 1][y] = 'x';
					d++;
				}
				if (map[x + 1][y] == '.') {
					q[r + d][0] = x + 1;
					q[r + d][1] = y;
					map[x + 1][y] = 'x';
					d++;
				}
				if (map[x][y - 1] == '.') {
					q[r + d][0] = x;
					q[r + d][1] = y - 1;
					map[x][y - 1] = 'x';
					d++;
				}
				if (map[x][y + 1] == '.') {
					q[r + d][0] = x;
					q[r + d][1] = y + 1;
					map[x][y + 1] = 'x';
					d++;
				}
			}
		}
		l = r;
		r += d;
	}
	int min_score = score(q[0]);
	FOR(i, 1, r)
	{
		min_score = min(min_score, score(q[i]));
	}
	printf("%d\n", (int) ceil(((double) min_score) / K) + 1);
}

int main() {
	core();
	return 0;
} ./Main.c: In function ‘core’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &H, &W, &K);
  ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", map[i]);
   ^