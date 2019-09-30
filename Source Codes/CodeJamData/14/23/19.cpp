#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;
bool OPEN=1;


bool g[55][55];
int n,m;
string s[55];
bool vis[55];
int sta[55],top;
bool vv[55];
void dfs(int x)
{
	vv[x]=1;
	for(int i=1;i<=n;i++)if(g[x][i])
	{
		if(!vv[i])
			dfs(i);
	}
}
bool can(int id,int pos)
{
	if(!g[id][sta[pos]])return 0;
	memset(vv,0,sizeof(vv));
	for(int i=1;i<=n;i++)if(vis[i])
	{
		bool in=0;
		for(int j=1;j<=pos;j++)if(sta[j]==i)in=1;
		if(!in)vv[i]=1;
	}
	dfs(sta[1]);
	for(int i=1;i<=n;i++)if(!vv[i])return 0;
	return 1;
}
void solve()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)cin>>s[i];
	memset(g,0,sizeof(g));
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a][b]=g[b][a]=1;
	}
	string ans="";
	memset(vis,0,sizeof(vis));
	top=0;
	for(int tt=1;tt<=n;tt++)
	{
		vector < pair<string,int> > gao;
		for(int i=1;i<=n;i++)if(!vis[i])gao.push_back(make_pair(s[i],i));
		sort(gao.begin(),gao.end());
		if(tt==1)
		{
			sta[++top]=gao.begin()->second;
			vis[sta[1]]=1;
			ans+=gao.begin()->first;
		}
		else
		{
			for(int i=0;i<gao.size();i++)
			{
				bool ok=0;
				int id=gao[i].second;
				for(int j=top;j>=1;j--)
				{
					if(can(id,j))
					{
						ans+=gao[i].first;
						top=j;sta[++top]=id;
						vis[id]=1;
						ok=1;
						break;
					}
				}
				if(ok)
				{
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
	if(OPEN)
	{
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	}
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		printf("Case #%d: ",cas);
		solve();
	}
	return 0;
}
