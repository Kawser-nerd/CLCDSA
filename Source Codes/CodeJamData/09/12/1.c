#include<stdio.h>
#include<string.h>

long long dp[400][4];
int b[400][4];
int s[20][20],w[20][20],t[20][20];
int n,m;

long long caltime(long long n,long long s,long long w,long long t) {
	long long c=s+w;
	long long t1=t%c,t2=t1+s;
	long long d=n%c;
	if (d<t1) d+=c;
	if (d<t2) return n;
	else return n+c+t1-d;
}

int main() {
	int i,j,k,t1,t2,N,cs=0,x,y;
	long long tt;

	for(scanf("%d",&N);N--;) {
		scanf("%d %d",&n,&m);
		for(i=n-1;i>=0;i--) for(j=0;j<m;j++) {
			scanf("%d %d %d",&s[i][j],&w[i][j],&t[i][j]);
			dp[i*m+j][0]=dp[i*m+j][1]=dp[i*m+j][2]=dp[i*m+j][3]=1000000000000000000LL;
			b[i*m+j][0]=b[i*m+j][1]=b[i*m+j][2]=b[i*m+j][3]=0;
		}
		dp[0][0]=0;
		for(i=0;i<n*m*4;i++) {
			for(t1=t2=-1,j=0;j<n*m;j++) for(k=0;k<4;k++)
				if (!b[j][k] && (t1<0 || dp[j][k]<dp[t1][t2]))
					t1=j,t2=k;
			b[t1][t2]=1;
			if (t1==n*m-1 && t2==3) break;
			x=t1/m,y=t1%m;
			if (t2==0) {
				if (x>0 && dp[t1-m][2]>dp[t1][t2]+2)
					dp[t1-m][2]=dp[t1][t2]+2;
				if (y>0 && dp[t1-1][1]>dp[t1][t2]+2)
					dp[t1-1][1]=dp[t1][t2]+2;
				tt=caltime(dp[t1][t2],s[x][y],w[x][y],t[x][y])+1;
				if (tt<dp[t1][2]) dp[t1][2]=tt;
				tt=caltime(dp[t1][t2],w[x][y],s[x][y],t[x][y]+s[x][y])+1;
				if (tt<dp[t1][1]) dp[t1][1]=tt;
			} else if (t2==1) {
				if (x>0 && dp[t1-m][3]>dp[t1][t2]+2)
					dp[t1-m][3]=dp[t1][t2]+2;
				if (y<m-1 && dp[t1+1][0]>dp[t1][t2]+2)
					dp[t1+1][0]=dp[t1][t2]+2;
				tt=caltime(dp[t1][t2],s[x][y],w[x][y],t[x][y])+1;
				if (dp[t1][3]>tt) dp[t1][3]=tt;
				tt=caltime(dp[t1][t2],w[x][y],s[x][y],t[x][y]+s[x][y])+1;
				if (dp[t1][0]>tt) dp[t1][0]=tt;
			} else if (t2==2) {
				if (x<n-1 && dp[t1+m][0]>dp[t1][t2]+2)
					dp[t1+m][0]=dp[t1][t2]+2;
				if (y>0 && dp[t1-1][3]>dp[t1][t2]+2)
					dp[t1-1][3]=dp[t1][t2]+2;
				tt=caltime(dp[t1][t2],s[x][y],w[x][y],t[x][y])+1;
				if (dp[t1][0]>tt) dp[t1][0]=tt;
				tt=caltime(dp[t1][t2],w[x][y],s[x][y],t[x][y]+s[x][y])+1;
				if (tt<dp[t1][3]) dp[t1][3]=tt;
			} else {
				if (x<n-1 && dp[t1+m][1]>dp[t1][t2]+2)
					dp[t1+m][1]=dp[t1][t2]+2;
				if (y<m-1 && dp[t1+1][2]>dp[t1][t2]+2)
					dp[t1+1][2]=dp[t1][t2]+2;
				tt=caltime(dp[t1][t2],s[x][y],w[x][y],t[x][y])+1;
				if (tt<dp[t1][1]) dp[t1][1]=tt;
				tt=caltime(dp[t1][t2],w[x][y],s[x][y],t[x][y]+s[x][y])+1;
				if (tt<dp[t1][2]) dp[t1][2]=tt;
			}
		}
		printf("Case #%d: %lld\n",++cs,dp[n*m-1][3]);
	}
	return 0;
}
