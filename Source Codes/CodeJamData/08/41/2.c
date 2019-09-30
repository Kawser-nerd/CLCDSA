#include<stdio.h>

int v[10001],c[10001],g[10001];
int dp[10001][2];
int n,m;

void run(int T) {
	int i,j,k;
	scanf("%d %d",&n,&m);
	for(i=0;i<=n;i++) dp[i][0]=dp[i][1]=1000000000;
	for(i=1;i<(n+1)/2;i++) {
		scanf("%d %d",&g[i],&c[i]);
	}
	for(;i<=n;i++) {
		scanf("%d",&v[i]);
		dp[i][v[i]]=0;
		dp[i][1-v[i]]=1000000000;
	}
	for(i=(n-1)/2;i;i--) {
		for(j=0;j<2;j++)
			if (dp[i<<1][j]<1000000000)
				for(k=0;k<2;k++)
					if (dp[i<<1|1][k]<1000000000) {
						if (g[i]) {
							int cur=j&k;
							if (dp[i][cur]>dp[i<<1][j]+dp[i<<1|1][k])
								dp[i][cur]=dp[i<<1][j]+dp[i<<1|1][k];
							if (c[i]) {
								cur=j|k;
								if (dp[i][cur]>dp[i<<1][j]+dp[i<<1|1][k]+1)
									dp[i][cur]=dp[i<<1][j]+dp[i<<1|1][k]+1;
							}
						}
						else {
							int cur=j|k;
							if (dp[i][cur]>dp[i<<1][j]+dp[i<<1|1][k])
								dp[i][cur]=dp[i<<1][j]+dp[i<<1|1][k];
							if (c[i]) {
								cur=j&k;
								if (dp[i][cur]>dp[i<<1][j]+dp[i<<1|1][k]+1)
									dp[i][cur]=dp[i<<1][j]+dp[i<<1|1][k]+1;
							}
						}
					}
	}
	if (dp[1][m]<1000000000) printf("Case #%d: %d\n",T,dp[1][m]); else printf("Case #%d: IMPOSSIBLE\n",T);
}

int main() {
	int N,cs=0;
	for(scanf("%d",&N);N--;)
		run(++cs);
	return 0;
}
