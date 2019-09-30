#include<stdio.h>
#define MOD 1000000007;
int N, i, j;
char S[100001], c;
long long int dp[100001][4];
int main(){
	c=getchar(); while(c!=10){S[N++]=c; c=getchar();}

	for(int i = N; i >= 0; --i){
		for(int j = 3; j >= 0; --j){
			if(i == N){
				dp[i][j] = (j == 3 ? 1 : 0);
			}else{
				dp[i][j] = dp[i+1][j] * (S[i] == '?' ? 3LL : 1LL);
				if(j < 3 && (S[i] == '?' || S[i] == j+'A')){
					dp[i][j] += dp[i+1][j+1];
				}
				dp[i][j] %= MOD;
			}
		}
	}
	printf("%lld\n", dp[0][0]);
}