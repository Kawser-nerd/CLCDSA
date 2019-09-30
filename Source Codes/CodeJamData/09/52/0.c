#include<stdio.h>
#include<string.h>

#define M 10009

char a[100][64];
int b[128][32];
int dp[16][8][16];
int n,m,p;
char str[128];
int pp[8][4];
int v[8];

int main() {
	int N,cs=0,i,j,k,l,c,d,t,ret;
	for(scanf("%d",&N);N--;) {
		scanf("%s %d",str,&m);
		scanf("%d",&n);
		memset(b,0,sizeof(b));
		for(i=0;i<n;i++) {
			scanf("%s",a[i]);
			for(j=0;a[i][j];j++) b[i][a[i][j]-'a']++;
		}
		memset(v,0,sizeof(v));
		for(p=i=0;str[i];i++) {
			if (str[i]!='+') pp[p][v[p]++]=str[i]-'a';
			else p++;
		}
		p++;
		memset(dp,0,sizeof(dp));
		printf("Case #%d:",++cs);
		for(i=0;i<p;i++) dp[0][i][0]=1;
		for(i=0;i<m;i++) {
			for(ret=j=0;j<p;j++) {
				for(d=0;d<n;d++) for(k=0;k<(1<<v[j]);k++) {
					for(l=0;l<=k;l++) if ((k&l)==l) {
						for(t=1,c=0;c<v[j];c++) if (l&(1<<c)) t=t*b[d][pp[j][c]]%M;
						t=t*dp[i][j][k^l]%M;
						if ((dp[i+1][j][k]+=t)>=M) dp[i+1][j][k]-=M;
					}
//printf("%d %d %x %d\n",i+1,j,k,dp[i+1][j][k]);
				}
				if ((ret+=dp[i+1][j][(1<<v[j])-1])>=M) ret-=M;
			}
			printf(" %d",ret);
		}
		puts("");
	}
	return 0;
}
