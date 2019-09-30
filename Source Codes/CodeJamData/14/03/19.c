#include <stdio.h>
#include <string.h>
#include <math.h>
#include <gmp.h>

#ifdef DEBUG
#define ddd(s, ...) printf(s, __VA_ARGS__)
#else
#define ddd(s, ...)
#endif

int find_solution(char board[50][50], int R, int C, int M) {
	int rem_R = R;
	int rem_C = C;
	int rem_M = M;

	memset(board, '.', 50*50);

	while (rem_M > 0) {
		if (((R>1 && rem_R == 1) || (C>1 && rem_C == 1)) && M != R*C-1)
			return (0);
		if (rem_R > rem_C) {
			/* fill row */
			int put_M = rem_C-1 == rem_M ? rem_M-1 :
			            (rem_M >= rem_C ? rem_C :
			            rem_M);
			int i;
			for (i=0; i<put_M; i++)
				board[rem_R-1][rem_C-i-1] = '*';
			rem_R--;
			rem_M -= put_M;
		} else {
			/* fill column */
			int put_M = rem_R-1 == rem_M ? rem_M-1 :
			            (rem_M >= rem_R ? rem_R :
			            rem_M);
			int i;
			for (i=0; i<put_M; i++)
				board[rem_R-i-1][rem_C-1] = '*';
			rem_C--;
			rem_M -= put_M;
		}
	}
	if (((R>1 && rem_R == 1) || (C>1 && rem_C == 1)) && M != R*C-1)
		return (0);

	return (1);
}

void place_start_point(char board[50][50], int R, int C) {
	board[0][0] = 'c';
}

int main(void) {
	int t, T;

	scanf("%d", &T);
	t = 0;
	while (t<T) {
		char board[50][50];
		int R, C, M;
		scanf("%d %d %d", &R, &C, &M);

		printf("Case #%d:\n", t+1);
		if (!find_solution(board, R, C, M)) {
			printf("Impossible\n");
		} else {
			int i, j;

			place_start_point(board, R, C);
			for (i=0; i<R; i++) {
				for (j=0; j<C; j++)
					printf("%c", board[i][j]);
				printf("\n");
			}
		}
		t++;
	}


	return (0);
}
