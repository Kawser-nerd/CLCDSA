#include <stdio.h>
#include <string.h>
long long n,m;
int mat[55][55];
long long nnd[55];
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T,cas=0;
	nnd[1]=1;
	nnd[2]=1;
	for(int i=3;i<=50;i++)
	{
		nnd[i]=nnd[i-1]*2;
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		memset(mat,0,sizeof(mat));
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<n;j++)mat[i][j]=1;
		}
		for(int i=n-1;i>=1;i--)
		{
			if(m>=nnd[i])
			{
				m-=nnd[i];
				mat[i][n]=1;
			}
		}
		if(m==0)
		{
			printf("Case #%d: POSSIBLE\n",++cas);
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					printf("%d",mat[i][j]);
					if(j==n)printf("\n");
				}
			}
		}
		else{
			printf("Case #%d: IMPOSSIBLE\n",++cas);
		}
	}
}