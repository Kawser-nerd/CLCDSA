#include<stdio.h>

#define M 100003

long long C[512][512];
long long dp[512][512];
long long r[512];

int main() {
	int i,j,k,N,cs=0,n;

	for(C[0][0]=i=1;i<=500;i++) for(C[i][0]=j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
	dp[1][0]=1;
	for(i=1;i<500;i++) {
		for(j=i+1;j<500;j++) for(k=0;k<i;k++) if (dp[i][k]) {
			dp[j][i]=(dp[j][i]+dp[i][k]*C[j-i-1][i-k-1])%M;
		}
	}
	for(i=2;i<=500;i++) for(j=1;j<i;j++) r[i]=(r[i]+dp[i][j])%M;

	for(scanf("%d",&N);N--;) {
		scanf("%d",&n);
		printf("Case #%d: %lld\n",++cs,r[n]);
	}
	return 0;
}
