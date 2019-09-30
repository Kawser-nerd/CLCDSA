#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 1e9

int max(int x, int y){return x<y?y:x;}

int main(void){
	int N,M,A[10],i;
	int cost[10]={0,2,5,5,4,5,6,3,7,6};
	scanf("%d%d",&N,&M);
	for(i=0;i<M;i++)scanf("%d",&A[i]);
	int dp[N+1];
	dp[0] = 0;
	for(i=1;i<=N;i++){
		dp[i] = -INF;
		for(int j=0;j<M;j++){
			if(i-cost[A[j]]>=0)	dp[i] = max(dp[i-cost[A[j]]]+1,dp[i]);
		}
	}
	while(N>0){
		int j = 0;
		for(i=0;i<M;i++){
			if(N-cost[A[i]]>=0 && dp[N-cost[A[i]]]==dp[N]-1) j = max(A[i],j);
		}
		printf("%d",j);
		N -= cost[j];
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&M);
  ^
./Main.c:12:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<M;i++)scanf("%d",&A[i]);
                  ^