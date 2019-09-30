#include<stdio.h>

#define min(a,b) ((a)<(b)?(a):(b))

int main(){
	int n,ng[3],i,dp[308][2]={0},j;//kaisu
	scanf("%d%d%d%d",&n,&ng[0],&ng[1],&ng[2]);
	dp[n][0]=1;
	for(i=299;i>=0;i--){
		for(j=0;j<3;j++)dp[ng[j]][0]=0;
		for(j=1;j<=3;j++){
		if(dp[i+j][0]==1&&dp[i+j][1]<=99){
			dp[i][0]=1;
			if(dp[i][1]==0)dp[i][1]=dp[i+j][1]+1;
			else dp[i][1]=min(dp[i][1],dp[i+j][1]+1);
		}
		}
	}
	for(j=0;j<3;j++)dp[ng[j]][0]=0;
	if(dp[0][0]==1&&dp[0][1]<=100)puts("YES");
	else puts("NO");
	//for(j=0;j<=300;j++)printf("%d,",dp[j][1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&n,&ng[0],&ng[1],&ng[2]);
  ^