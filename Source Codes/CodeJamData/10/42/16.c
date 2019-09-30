#include<stdio.h>
#include<string.h>

int a[1024];
int dp[11][2048][11];
int p[1024];
int n;

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)<(b)?(b):(a))

int main() {
	int N,cs=0,i,j,k,l,m,t,mask,r;

	for(scanf("%d",&N);N--;) {
		scanf("%d",&n);
		for(i=0;i<(1<<n);i++) scanf("%d",&a[i]);
		for(i=n-1;i>=0;i--) for(j=0;j<(1<<i);j++) scanf("%d",&p[(1<<i)|j]);
		memset(dp,0x7f,sizeof(dp));
		for(i=0;i<(1<<n);i++) dp[n][i][0]=0;
		for(i=n-1;i>=0;i--) {
			for(j=0;j<(1<<n);j++) for(k=0;k<=a[j];k++) if (dp[i+1][j][k]!=0x7f7f7f7f) {
				l=0;
				mask=(j&((1<<n)-(1<<(n-i-1))))^(1<<(n-i-1));
				for(m=0;m<(1<<(n-i-1));m++) {
					t=0x7f7f7f7f;
					for(r=0;r<=a[mask|m];r++) t=MIN(t,dp[i+1][mask|m][r]);
					l=MAX(l,t);
				}
				if (l!=0x7f7f7f7f) dp[i][j][k]=MIN(dp[i][j][k],l+dp[i+1][j][k]+p[(1<<i)|(mask>>(n-i))]);
				if (k==a[j]) continue;
				l=0;
				for(m=0;m<(1<<(n-i-1));m++) {
					t=0x7f7f7f7f;
					for(r=0;r<a[mask|m];r++) t=MIN(t,dp[i+1][mask|m][r]);
					l=MAX(l,t);
				}
				if (t!=0x7f7f7f7f) dp[i][j][k+1]=MIN(dp[i][j][k+1],dp[i+1][j][k]+l);
			}
//			for(j=0;j<(1<<n);j++) for(k=0;k<=a[j];k++)
//				printf("%d %d %d %d\n",i,j,k,dp[i][j][k]);
		}
		r=0;
		for(i=0;i<(1<<n);i++) {
			t=0x7f7f7f7f;
			for(j=0;j<=a[i];j++) t=MIN(t,dp[0][i][j]);
			r=MAX(t,r);
		}
		printf("Case #%d: %d\n",++cs,r);
	}
	return 0;
}
