#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[1000];
char msg[]="welcome to code jam";
int n,m=19;
long long f[1000][20],g[1000][20];

void init()
{
	int i, j;
	
	gets(buf);

	n=strlen(buf);
	for(j=0;j<m;j++) {
		g[n][j]=n;
		for(i=n-1;i>=0;i--)
			if(buf[i]==msg[j]) g[i][j]=i;
			else g[i][j]=g[i+1][j];
	}

}

void solve()
{
	int i, j,k;
	
	for(i=n;i>=0;i--)
		for(j=m;j>=0;j--) {
			f[i][j]=0;
			if(j==m) f[i][j]=1;
			else if (i==n) f[i][j]=0;
			else {
				k=g[i][j];
				while(k!=n) {
					f[i][j]+=f[k+1][j+1];
					f[i][j]%=10000;
					k=g[k+1][j];
				}
			}
		}
	printf("%.4d\n", f[0][0]);
}

int main()
{
	int v,V;

	scanf("%d\n", &V);
	for(v=1;v<=V;v++) {
		init();
		printf("Case #%d: ",v);
		solve();
	}
	
	return 0;
}
