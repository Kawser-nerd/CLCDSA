#include<stdio.h>

int a[10000][2];
int dp[10000];
int n,m;

int main() {
	int N,cs=0;
	int i,j,k;
	for(scanf("%d",&N);N--;) {
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d %d",&a[i][0],&a[i][1]),dp[i]=-1;
		scanf("%d",&m);
		dp[0]=a[0][0];
		int f=0;
		for(i=0;i<n && !f;i++) if (dp[i]>=0) {
			if (a[i][0]+dp[i]>=m) f=1;
			for(j=i+1;j<n && a[j][0]<=a[i][0]+dp[i];j++) {
				if (a[j][0]-a[i][0]<=a[j][1]) k=a[j][0]-a[i][0]; else k=a[j][1];
				if (k>dp[j]) dp[j]=k;
			}
		}
		if (f) printf("Case #%d: YES\n",++cs); else printf("Case #%d: NO\n",++cs);
	}	
	return 0;
}
