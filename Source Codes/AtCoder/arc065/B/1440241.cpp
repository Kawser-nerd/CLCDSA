#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
int n;
void dfs(int x,vector<int> *w,int *ans,int sign)
{
	ans[x]=sign;
	for(int i:w[x])
		if(ans[i]==-1)dfs(i,w,ans,sign);
}
vector<int> u[200011],v[200011];
int ansx[200011],ansy[200011];
int main()
{
	int p,q;
	scanf("%d%d%d",&n,&p,&q);
	while(p--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		u[x].push_back(y);
		u[y].push_back(x);
	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(ansx,-1,sizeof ansx);
	memset(ansy,-1,sizeof ansy);
	for(int i=1;i<=n;i++)
		if(ansx[i]==-1)dfs(i,u,ansx,i);
	for(int i=1;i<=n;i++)
		if(ansy[i]==-1)dfs(i,v,ansy,i);
	map<pair<int,int>,int> m;
	for(int i=1;i<=n;i++)m[make_pair(ansx[i],ansy[i])]++;
	for(int i=1;i<=n;i++)printf("%d ",m[make_pair(ansx[i],ansy[i])]);
	putchar('\n');
	return 0;
}