#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2010;
int n,head[N],to[N*2],nex[N*2],x,y,tot,k,ans;
void link(int x,int y)
{
	nex[++tot]=head[x];
	to[head[x]=tot]=y;
}
int dfs(int now, int lim, int f)
{
	if(lim<0)
		return 0;
	int ans=1;
	for(int i=head[now]; i; i=nex[i])
		if(to[i]!=f)
			ans+=dfs(to[i],lim-1,now);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1; i<n; i++)
	{
		scanf("%d%d",&x,&y);
		link(x,y);
		link(y,x);
	}
	for(int i=1; i<=n; i++)
	{
		if(k&1)
			for(int j=head[i];j;j=nex[j])
				ans=max(ans,dfs(i,k/2,to[j])+dfs(to[j],k/2,i));
		else
			ans=max(ans,dfs(i,k/2,0));
	}
	printf("%d",n - ans);
}