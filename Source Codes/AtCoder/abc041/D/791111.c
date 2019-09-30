#include <stdio.h>

int prec[16];
long long dp[65536];

int main(void){
	int n, m, i, p2, S;
	scanf("%d%d", &n, &m);
	p2 = 1 << n;
	for(i = 0; i < n; ++i){
		prec[i] = 1 << i;
	}
	for(i = 0; i < m; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		prec[y - 1] |= 1 << (x - 1);
	}
	
	dp[0] = 1;
	for(S = 0; S < p2; ++S){
		for(i = 0; i < n; ++i){
			if(!(S & prec[i])){
				dp[S | 1 << i] += dp[S];
			}
		}
	}
	printf("%lld\n", dp[p2 - 1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &n, &m);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &x, &y);
   ^