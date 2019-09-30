#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define INF 10000000000
#define M 1000000007

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	long N, A;
	long i, j, k;
	long ans = 0;
	long x[51];
	long *dp[51][51];
	long count[2500] = {0};
	
	scanf("%ld %ld", &N, &A);
	for(i=0;i<=N;i++) {
		for(j=0;j<=N;j++) {
			dp[i][j] = (long *)malloc(sizeof(long) * 2501);
			memset(dp[i][j], 0, sizeof(long) * 2501);
		}
	}
	
	for(i=1;i<=N;i++) {
		scanf("%ld", &x[i]);
		count[x[i]]++;
	}
	
	for(i=0;i<=N;i++)
			dp[i][0][0] = 1;
	
	for(i=1;i<=N;i++)
		for(j=1;j<=i;j++)
			for(k=0;k<=2500;k++)
				dp[i][j][k] = k < x[i] ? dp[i-1][j][k] : dp[i-1][j][k] + dp[i-1][j-1][k-x[i]];
	
	for(j=1;j<=N;j++) ans += dp[N][j][A*j];
	
	printf("%ld\n", ans);
	
	for(i=1;i<=N;i++) for(j=1;j<=N;j++) free(dp[i][j]);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld", &N, &A);
  ^
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &x[i]);
   ^