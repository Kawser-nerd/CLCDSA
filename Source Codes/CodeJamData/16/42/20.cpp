#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
double A[400],dp[210][210];
int len;
double solve(){
	int n,K; scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) scanf("%lf",&A[i]);
	sort(A+1,A+n+1); double ans=0;
	for (int t=0;t<=K;t++){
		len=0;
		memset(dp,0x00,sizeof dp);
		dp[0][0]=1;
		for (int i=1;i<=K;i++){
			double now; if (i<=t) now=A[i]; else now=A[n-(i-t)+1];
			for (int j=0;j<=i;j++) dp[i][j]+=dp[i-1][j]*(1-now),dp[i][j+1]+=dp[i-1][j]*now;
		}
		ans=max(dp[K][K/2],ans);
	}
	return ans;
}
int main(){
	freopen("Bl.in","r",stdin);
	freopen("Bl.out","w",stdout);
	int t; scanf("%d",&t);
	for (int tt=1;tt<=t;tt++){
		printf("Case #%d: %.11lf\n",tt,solve());
	}
}
