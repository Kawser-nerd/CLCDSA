#include<stdio.h>
#include<string.h>
int dp[300][300];
inline int ABS(int a){return a>0?a:-a;}
int main(){
	int t,cas=1,D,I,m,n,i,j,a,aa;
	scanf("%d",&t);
	while(t--){
		memset(dp,-1,sizeof(dp));
		scanf("%d%d%d%d",&D,&I,&m,&n);
		scanf("%d",&a);
		for(i=0;i<=255;i++)dp[0][i]=ABS(i-a);
		for(i=1;i<n;i++){
			scanf("%d",&a);
			for(j=0;j<=255;j++)dp[i][j]=ABS(j-a)+i*D;
			for(aa=0;aa<=255;aa++){
				for(j=0;j<=255;j++){
					dp[i][j]<?=dp[i-1][j]+D;
					if(aa!=j&&m)dp[i][aa]<?=dp[i-1][j]+(ABS(j-aa)-1)/m*I+ABS(aa-a);
					else dp[i][aa]<?=dp[i-1][aa]+ABS(aa-a);
				}
			}
		}
		int ans=1000000000;
		for(i=0;i<=255;i++)if(dp[n-1][i]!=-1)ans<?=dp[n-1][i];
		printf("Case #%d: %d\n",cas++,ans);
	}
}
