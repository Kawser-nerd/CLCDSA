#include<stdio.h>
#define MOD 1000000007;
int N, i, j;
char S[100001], c;
long long int dp[100001][4];
int main(){
	c=getchar(); while(c!=10){S[N++]=c; c=getchar();}

	dp[N][3]=1;
	for(i=N-1; i>=0; --i){
		{
			dp[i][3] = dp[i+1][3] * (S[i] == '?' ? 3LL : 1LL);
			dp[i][3] %= MOD;
		}
		for(j=2; j>=0; --j){
			if(S[i]=='?'){
				dp[i][j] = dp[i+1][j]*3;
			}else{
				dp[i][j] = dp[i+1][j];
			}
			if(S[i] == '?' || S[i] == j+'A'){
				dp[i][j] += dp[i+1][j+1];
			}
			dp[i][j] %= MOD;
		}
	}
	printf("%lld\n", dp[0][0]);
}