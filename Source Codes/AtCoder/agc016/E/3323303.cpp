#include<cstdio>
#include<algorithm>
#define MAXN 406
#define MAXM 100006
using namespace std;
int n,m,p[MAXN],fa[MAXN],u[MAXM],v[MAXM],ans,vis[MAXN][MAXN];
int root(int x)
{
	if(fa[x]!=x) fa[x]=root(fa[x]);
	return fa[x];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u[i],&v[i]);
	for(int i=1;i<=n;i++)
	{
		p[i]=1;
		for(int j=1;j<=n;j++)
			fa[j]=j;
		for(int j=m;j>=1;j--)
		{
			int l=root(u[j]);
			int r=root(v[j]);
			if(l!=root(i)&&r!=root(i)) continue;
			if(l==root(i)&&r==root(i))
			{
				p[i]=0;
				break;
			}
			if(l!=root(i)) fa[l]=root(i);
			if(r!=root(i)) fa[r]=root(i);
		}
		if(!p[i]) continue;
		for(int j=1;j<=n;j++)
			if(root(j)==root(i)) vis[i][j]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(p[i]&&p[j])
			{
				int ok=1;
				for(int k=1;k<=n;k++)
					if(vis[i][k]&&vis[j][k])
					{
						ok=0;
						break;
					}
				ans+=ok;
			}
	printf("%d",ans);
}