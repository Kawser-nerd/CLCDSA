#include<cstdio>

const int maxn=200+10;
bool map[maxn][maxn];
bool flag[maxn];
int link[maxn];
int n,m,t,cases;
int p[maxn][maxn];

bool find(int u)
{
	for (int v=1;v<=n;v++)
	if (!flag[v] && map[u][v])
	{
		flag[v]=true;
		if (!link[v] || find(link[v]))
		{
			link[v]=u;
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);

	for (scanf("%d",&t);t;t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&p[i][j]);
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			map[i][j]=false;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (i!=j)
		{
			bool sign=true;
			for (int k=1;k<=m;k++)
				sign&=p[i][k]>p[j][k];
			map[i][j]=sign;
		}
	int res=0;
		for (int i=1;i<=n;i++) flag[i]=link[i]=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++) flag[j]=false;
			if (find(i)) res++;
		}
		printf("Case #%d: %d\n",++cases,n-res);
	}

}