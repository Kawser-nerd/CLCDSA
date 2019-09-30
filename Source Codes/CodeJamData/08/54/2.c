#include<stdio.h>
#include<string.h>

#define M 10007
int dp[128][128];
int n,m,r;

void run(int T) {
	memset(dp,0,sizeof(dp));
	scanf("%d %d %d",&n,&m,&r);
	for(int i=0;i<r;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		dp[x][y]=-1;
	}
	dp[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			if (dp[i][j]<0) continue;
			if (i+2<n && j+1<m && dp[i+2][j+1]>=0)
				if ((dp[i+2][j+1]+=dp[i][j])>=M) dp[i+2][j+1]-=M;
			if (i+1<n && j+2<m && dp[i+1][j+2]>=0)
				if ((dp[i+1][j+2]+=dp[i][j])>=M) dp[i+1][j+2]-=M;
		}
	printf("Case #%d: %d\n",T,dp[n-1][m-1]);
}

int main() {
	int N,cs=0;
	for(scanf("%d",&N);N--;)
		run(++cs);
	return 0;
}
