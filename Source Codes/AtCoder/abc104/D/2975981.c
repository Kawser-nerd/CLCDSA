#include <stdio.h>
#include <string.h>

typedef long long ll;

ll dp[100005][4];
char S[100005];

ll mod =1000000007ll;

int main(){

	scanf("%s",S);

	int len=strlen(S);

	int i,j;

	dp[0][0]=1ll;

	for(i=0;i<len;i++){
		if(S[i]=='A' || S[i]=='?'){
			for(j=0;j<4;j++){
				dp[i+1][j]+=dp[i][j];
				dp[i+1][j]%=mod;
			}
			dp[i+1][1]+=dp[i][0];
			dp[i+1][1]%=mod;
		}
		if(S[i]=='B' || S[i]=='?'){
			for(j=0;j<4;j++){
				dp[i+1][j]+=dp[i][j];
				dp[i+1][j]%=mod;
			}
			dp[i+1][2]+=dp[i][1];
			dp[i+1][2]%=mod;
		}
		if(S[i]=='C' || S[i]=='?'){
			for(j=0;j<4;j++){
				dp[i+1][j]+=dp[i][j];
				dp[i+1][j]%=mod;
			}
			dp[i+1][3]+=dp[i][2];
			dp[i+1][3]%=mod;
		}
	}

	printf("%lld\n",dp[len][3]);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S);
  ^