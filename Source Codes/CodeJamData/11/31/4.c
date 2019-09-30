#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void solve(const int n)
{
	int R, C;
	int r, c;
	char M[50][50];

	scanf("%d %d ", &R, &C);
	for (r = 0; r < R; r++) {
		for (c = 0; c < C; c++) {
			scanf("%c",&M[r][c]);
		}
		scanf(" ");
	}
	for (r = 0; r < R; r++) {
		for (c = 0; c < C; c++) {
			if(M[r][c] != '#') continue;
			if (r == R-1) goto fail;
			if (c == C-1) goto fail;
			if (M[r][c]     == '#') M[r][c]     = '/' ; else goto fail;
			if (M[r][c+1]   == '#') M[r][c+1]   = '\\'; else goto fail;
			if (M[r+1][c]   == '#') M[r+1][c]   = '\\'; else goto fail;
			if (M[r+1][c+1] == '#') M[r+1][c+1] = '/' ; else goto fail;
		}
	}
	
	printf("Case #%d:\n", n);
	for (r = 0; r < R; r++) {
		for (c = 0; c < C; c++) {
			printf("%c",M[r][c]);
		}
		printf("\n");
	}
	return;
fail:
	printf("Case #%d:\nImpossible\n", n);
}

int main(int argc, char **argv)
{
	int T;
	int i;

	scanf("%d ", &T);
	for (i = 0; i < T; i++) {
		solve(i+1);
	}
	return 0;
}
