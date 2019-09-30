#include <stdio.h>

#define INF 1e100

int g[111][111];
int n;
int hr[111],hs[111]; /* horse reach, horse speed */

double dp[101][101]; /* [i][j]: at city i using horse from j: best time */
int dpleft[101][101]; /* horse reach left for state */

void solve() {
	double tid;
	int i,j,q,u,v;
	scanf("%d %d",&n,&q);
	for(i=0;i<n;i++) scanf("%d %d",&hr[i],&hs[i]);
	for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&g[i][j]);
	while(q--) {
		scanf("%d %d",&u,&v);
		for(i=0;i<n;i++) for(j=0;j<n;j++) dp[i][j]=INF;
		dp[1][0]=g[0][1]/(double)hs[0];
		dpleft[1][0]=hr[0]-g[0][1];
		for(i=1;i<n-1;i++) for(j=0;j<i;j++) if(dp[i][j]<INF) {
			/* take new horse */
			if(g[i][i+1]<=hr[i]) {
				tid=dp[i][j]+g[i][i+1]/(double)hs[i];
				if(dp[i+1][i]>tid) dp[i+1][i]=tid,dpleft[i+1][i]=hr[i]-g[i][i+1];
			}
			/* use old horse */
			if(dpleft[i][j]<g[i][i+1]) continue;
			tid=dp[i][j]+g[i][i+1]/(double)hs[j];
			if(dp[i+1][j]>tid) dp[i+1][j]=tid,dpleft[i+1][j]=dpleft[i][j]-g[i][i+1];
		}
		tid=1e100;
		for(i=0;i<n;i++) if(tid>dp[n-1][i]) tid=dp[n-1][i];
		printf("%.10f",tid);
		if(q) printf(" ");
	}
	printf("\n");
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
