#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
int n,m,cc,vis[705],col[705],num[705][2],f[2][705]={{1}},e[705][705],ans=1e9;
void dfs(int x,int c)
{
	num[cc][c]++;col[x]=c;vis[x]=1;
	for (int i=1;i<=n;i++) if (x!=i && !vis[i] && !e[x][i]) dfs(i,c^1);
	else if (x!=i && !e[x][i] && col[i]==c) __builtin_exit((int)puts("-1")*0);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		e[u][v]=e[v][u]=1;
	}
	for (int i=1;i<=n;i++) if (!vis[i])
	{
		cc++;
		dfs(i,0);
	}
	for (int i=1,b=1;i<=cc;i++,b^=1)
	{
		__builtin_memset(f[b],0,sizeof(f[b]));
		for (int j=0;j<=n;j++) if (f[b^1][j]) f[b][j+num[i][0]]=f[b][j+num[i][1]]=1;
	}
	for (int i=0;i<=n;i++) if (f[cc&1][i]) ans=min(ans,i*(i-1)/2+(n-i)*(n-i-1)/2);
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&u,&v);
   ^