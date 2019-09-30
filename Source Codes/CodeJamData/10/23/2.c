#include <stdio.h>
#include <memory.h>
#define M 100003

typedef long long I;

int f[600][600];
int P[600][600];

int main()
{
	int TT,C=0,n,m;
	int i,j,k;
	P[0][0]=1;
	for(i=1;i<=500;i++)
	{
		P[i][0]=P[i][i]=1;
		for(j=1;j<i;j++)
			P[i][j]=(P[i-1][j-1]+P[i-1][j])%M;
	}
	for(i=2;i<=500;i++)
	{
		f[i][1]=1;
		for(j=2;j<i;j++)
		{
			f[i][j]=0;
			for(k=j*2-i>1?j*2-i:1;k<j;k++)
				f[i][j]=(f[i][j]+(I)P[i-j-1][j-k-1]*f[j][k])%M;
		}
	}
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	scanf("%d",&TT);
	while(TT--)
	{
		printf("Case #%d: ",++C);
		scanf("%d",&n);
		m=0;
		for(i=1;i<n;i++)m+=f[n][i];
		printf("%d\n",m%M);
	}
	return 0;
}