#include <cstdio>

#define P 10005
#define N 105
#define inf 1000000000

int t,test;
int p,n,i,j,k,ans,x;
int a[N];
int f[N][N];

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&test);
	for(t=1;t<=test;t++)
	{
		scanf("%d%d",&p,&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[0]=0;
		a[n+1]=p+1;
		for(i=0;i<n+1;i++)
			f[i][1]=0;
		for(j=2;j<=n+1;j++)
			for(i=0;i<=n+1-j;i++)
			{
				f[i][j]=inf;
				for(k=1;k<j;k++)
				{
					x=f[i][k]+f[i+k][j-k]+a[i+j]-a[i]-2;
					if(x<f[i][j])
						f[i][j]=x;
				}
			}
		printf("Case #%d: %d\n",t,f[0][n+1]);
	}
	return 0;
}

