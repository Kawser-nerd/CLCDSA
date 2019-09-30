#include <stdio.h>
#include <string.h>
#define mod 1000000007 //10^9+7

int main(void){
	char S[100001];
	scanf("%s",S);
	int len = strlen(S),i,j;
	long long dp[len+1][4];
	dp[len][3] = 1;
	dp[len][0] = 0;
	dp[len][1] = 0;
	dp[len][2] = 0;
	for(i=len-1;i>=0;i--){
		int m=1;
		if(S[i] == '?')m=3;
		dp[i][3] = m*dp[i+1][3]%mod;
		for(j=2;j>=0;j--){
			int n=1,m=0;
			if(S[i]=='?')n=3;
			if(S[i]=='?' || S[i] =="ABC"[j])m=1;
			dp[i][j] = (n*dp[i+1][j]+m*dp[i+1][j+1])%mod;
		}
	}
	printf("%lld",dp[0][0]);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S);
  ^