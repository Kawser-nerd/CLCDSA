#include <stdio.h>

#define INF 10000
#define MAXH 720
#define MAX (MAXH+MAXH)

int act[MAX]; /* activity from i to i+1 belongs to 0:noone, 1=cameron, 2:jamie */
int dp[MAX+1][MAXH+1][2]; /* dp[i][j][k]: number of changes after i minutes and cameron watched baby minutes, k=who watches */

void solve() {
	int ac,aj,c,d;
	int i,j,k,who,i2,j2,k2,ans;
	scanf("%d %d",&ac,&aj);
	for(i=0;i<MAX;i++) act[i]=0;
	for(i=0;i<ac;i++) {
		scanf("%d %d",&c,&d);
		for(j=c;j<d;j++) act[j]=1;
	}
	for(i=0;i<aj;i++) {
		scanf("%d %d",&c,&d);
		for(j=c;j<d;j++) act[j]=2;
	}
	for(i=0;i<MAX+1;i++) for(j=0;j<MAXH+1;j++) for(k=0;k<2;k++) dp[i][j][k]=INF;
	dp[0][0][0]=dp[0][0][1]=0;
	for(i=0;i<MAX;i++) for(j=0;j<=MAXH;j++) for(k=0;k<2;k++) if(dp[i][j][k]<INF) {
		who=k+1;
		if(act[i] && act[i]!=who) continue; /* wrong person */
		i2=i+1; j2=j; k2=k;
		if(who==1) j2++;
		if(j2>MAXH) continue;
		/* don't change */
		if(dp[i2][j2][k2]>dp[i][j][k]) dp[i2][j2][k2]=dp[i][j][k];
		/* change */
		k2^=1;
		if(dp[i2][j2][k2]>dp[i][j][k]+1) dp[i2][j2][k2]=dp[i][j][k]+1;
	}
	ans=dp[MAX][MAXH][0];
	if(ans>dp[MAX][MAXH][1]) ans=dp[MAX][MAXH][1];
	if(ans&1) ans++;
	printf("%d\n",ans);
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
