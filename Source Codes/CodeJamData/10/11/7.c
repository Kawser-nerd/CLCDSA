#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define R 'R'
#define B 'B'
#define E '.'

#define FR 0x1
#define FB 0x2
typedef  char (Board) [50][50];

Board board;
int n, k, T;

void rotate(Board board, int n) {
	int i, j, k;
	for (i = 0; i < n; i++) {
		j = n - 1;
		k = n - 1;
		while (k >= 0) {
			while (k >= 0 && board[i][k] == E) {
				k--;
			}
			if (k >= 0) {
				board[i][j] = board[i][k];
				j--;
				k--;
			}
		}
		while (j >= 0) {
			board[i][j] = E;
			j--;
		}
	}
}

int printb(Board board) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

int check(Board board, int x0, int y0, int ddx, int ddy, int dx, int dy, int ret) {
	int ccnt = 0;
	char last = E,
	     cur;
	int x, y, i, j;

	if (ret == (FR | FB))
		return ret;
	x = x0;
	y = y0;
	while (x < n && y < n && x >= 0 && y >= 0) {
		i = x;
		j = y;
		while (i < n && j < n && i >= 0 && j >= 0) {
			cur = board[i][j];
			if (last != E && cur == last) {
				ccnt++;
			} else {
				ccnt = 1;
			}
			if (ccnt == k) {
				if (cur == R)
					ret |= FR;
				else
					ret |= FB;
			}
			last = cur;
			i += dx;
			j += dy;
		}
		last = E;
		ccnt = 0;
		x += ddx;
		y += ddy;
	}
	return ret;


}

int main() {
	int t, i, j;
	int ret;
	scanf("%d\n", &T);
	
	for (t = 0; t < T; t++) {
		scanf("%d %d\n", &n, &k);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%c", &board[i][j]);
			}
			scanf("\n");
		}

		rotate(board, n);
		// printb(board);
		ret = 0;
		ret |= check(board, 0, 0, 1, 0, 0, 1, ret);
		ret |= check(board, 0, 0, 0, 1, 1, 0, ret);
		ret |= check(board, 0, 0, 1, 0, 1, 1, ret);
		ret |= check(board, 0, 0, 0, 1, 1, 1, ret);
		ret |= check(board, 0, n - 1, 0, -1, 1, -1, ret);
		ret |= check(board, 0, n - 1, 1, 0, 1, -1, ret);

		printf("Case #%d: ", t + 1);
		switch(ret) {
			case 3:
				printf("Both\n");
				break;
			case FB:
				printf("Blue\n");
				break;
			case FR:
				printf("Red\n");
				break;
			case 0:
				printf("Neither\n");
				break;
		}
	}

	return 0;
}
