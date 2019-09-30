#include <stdio.h>
#include <stdlib.h>
#define MOD 10007

int r[111][111], w[111][111];

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, R, C, N, a, b, test, T;
	
	scanf("%d\n", &T);
	
	for (test=1; test<=T; test++) {
		scanf("%d %d %d", &R, &C, &N);
		
		for (i=1; i<=R; i++) {
			for (j=1; j<=C; j++) {
				w[i][j] = 0;
				r[i][j] = 0;
			}
		}
		
		for (i=1; i<=N; i++) {
			scanf("%d %d", &a, &b);
			r[a][b] = 1;
		}
		r[1][1] = w[1][1] = 1;
		
		for (i=1; i<=R; i++) {
			for (j=1; j<=C; j++) {
				if ( r[i][j] ) continue;
				
				if ( i-2 > 0 && j-1 > 0 ) w[i][j] += w[i-2][j-1];
				if ( i-1 > 0 && j-2 > 0 ) w[i][j] += w[i-1][j-2];
				
				w[i][j] %= MOD;
			}
		}
		
		printf("Case #%d: %d\n", test, w[R][C]);
	}
}
