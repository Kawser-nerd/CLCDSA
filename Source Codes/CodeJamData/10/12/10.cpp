#include <cstdio>
#include <algorithm>
using namespace std;
#include <cstring>
#define maxn 105
#define maxm 305
#define inf 1000000000

int f[maxn][maxm],dist[maxm][maxm],D,I,M,n,a[maxn];

inline int abs(int x)
{
	if (x<0) return -x;
	return x;
}

int main()
{
	freopen("B_large.in","r",stdin);
	freopen("B_large.out","w",stdout);
	
	int T,test=1;
	for (scanf("%d",&T);test<=T;++test)
	{
		scanf("%d%d%d%d",&D,&I,&M,&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for (int i=0;i<=255;++i)
		{
			for (int j=0;j<=255;++j)
			if (abs(i-j)<=M) dist[i][j]=I;
			else dist[i][j]=inf;
			dist[i][i]=0;
		}
		
		for (int k=0;k<=255;++k)
			for (int i=0;i<=255;++i)
				for (int j=0;j<=255;++j)
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		
		for (int i=0;i<=255;++i)
			f[0][i]=0;
		for (int i=1;i<=n;++i)
		{
			for (int j=0;j<=255;++j)
			{
				f[i][j]=f[i-1][j]+D;
				for (int k=max(0,j-M);k<=255 && k<=j+M;++k)
					f[i][j]=min(f[i][j],f[i-1][k]+abs(a[i]-j));
			}
			
			for (int j=0;j<=255;++j)
				for (int k=0;k<=255;++k)
					f[i][j]=min(f[i][j],f[i][k]+dist[k][j]);
		}
		int ans=inf;
		for (int i=0;i<=255;++i)
			ans=min(ans,f[n][i]);
		
		printf("Case #%d: %d\n",test,ans);
	}
	return 0;
}
