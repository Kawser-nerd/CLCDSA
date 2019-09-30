#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf=0x1ff00000;
int dp[1<<12][12];
int cost[1<<12];

int main(){
	int tt,cas,i,j,p,x;
	scanf("%d",&tt);
	for (cas=1;cas<=tt;cas++){
		scanf("%d",&p);
		for (i=p;i>=0;i--)
			for (j=0;j<(1<<i);j++)
				scanf("%d",&cost[(1<<i)+j]);
		for (i=0;i<(1<<p);i++){
			for (j=0;j<=p;j++)
				dp[(1<<p)+i][j]=inf;
			x=p-cost[(1<<p)+i];
			for (j=x;j<=p;j++)
				dp[(1<<p)+i][j]=0;
		}
		for (i=(1<<p)-1;i>=1;i--){
			for (j=0;j<p;j++){
				dp[i][j]=min(inf,min(dp[i*2][j]+dp[i*2+1][j],
					cost[i]+dp[i*2][j+1]+dp[i*2+1][j+1]));
				if (j>1) dp[i][j]=min(dp[i][j],dp[i][j-1]);
			}
		}
		printf("Case #%d: %d\n",cas,dp[1][0]);
	}
	return 0;
}
