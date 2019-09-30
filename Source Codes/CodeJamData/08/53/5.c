#include <stdio.h>
#include <stdlib.h>

int dp[11][(1<<11)], R, C;
char u[11][11];

int cnt(int u) {
	int ans = 0;
	while (u > 0) {
		ans += (u&1);
		u >>= 1;
	}
	return ans;
}

int is(int a, int b) {
	return (a&(1<<b));
}

int check(int a, int b) {
	int i;
	
	if ( (b&1) && (a&2) ) return 0;
	
	for (i=1; i<(1<<C); i++) {
		if ( is(b,i) && ( is(a,i-1) || is(a,i+1) ) ) {
			return 0;
		}
	}
	
	return 1;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, k, T, test, ans = 0;
	scanf("%d\n", &T);
	
	for (test=1; test<=T; test++) {
		scanf("%d %d\n", &R, &C);
		
		for (i=0; i<R; i++) {
			for (j=0; j<C; j++) {
				scanf("%c", &u[i][j]);
			}
			scanf("\n");
		}
		
		for (j=0; j<(1<<C); j++) {
			for (k=0; k<C; k++) {
				if (j&(1<<k)) {
					if ( u[0][k] == 'x' || (j&(1<<(k+1))) || ( k > 0 && (j&(1<<(k-1))) ) ) {
						dp[0][j] = 0;
						break;
					}
				}
			}
			if ( k == C ) dp[0][j] = cnt(j);
		}
		
		for (i=1; i<R; i++) {
			for (j=0; j<(1<<C); j++) {
				for (k=0; k<C; k++) {
					if (j&(1<<k)) {
						if ( u[i][k] == 'x' || (j&(1<<(k+1))) || ( k > 0 && (j&(1<<(k-1))) ) ) {
							dp[i][j] = 0;
							break;
						}
					}
				}
				
				if ( k == C ) {
					dp[i][j] = 0;
					for (k=0; k<(1<<C); k++) {
						if ( dp[i-1][k] + cnt(j) > dp[i][j] && check(k, j) ) {
							dp[i][j] = dp[i-1][k] + cnt(j);
						}
					}
				}
			}
		}
		
		ans = 0;
		for (j=0;j<(1<<C); j++) {
			if ( dp[R-1][j] > ans ) ans = dp[R-1][j];
		}
		
		printf("Case #%d: %d\n", test, ans);
	}
	
	return 0;
}
