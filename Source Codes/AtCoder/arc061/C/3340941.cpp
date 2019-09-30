#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int maxn = 2e6+100;
int n,m,cnt;
int x,y,z;
vector<int> f[maxn],g[maxn];
map<pair<int,int>,int> P;
int get(int x,int y)
{
	if(P.find(make_pair(x,y))!=P.end()) return P[make_pair(x,y)];
	else return P[make_pair(x,y)]=++cnt;
}
void add(int x,int y,int z)
{
	f[x].push_back(y);f[y].push_back(x);
	g[x].push_back(z);g[y].push_back(z);
}
int dis[maxn];
bool vis[maxn];
void spfa(int src)
{
	memset(dis,63,sizeof(dis));
	queue<int> Q;
	Q.push(1);
	vis[1]=true;
	dis[1]=0;
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		for(int i=0;i<f[u].size();i++)
		{
			int v=f[u][i];
			if(dis[v]>dis[u]+g[u][i])
			{
				dis[v]=dis[u]+g[u][i];
				if(!vis[v])
				{
					vis[v]=true;
					Q.push(v);
				}
			}
		}
		vis[u]=false;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	cnt=n;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		int id1=get(x,z),id2=get(y,z);
		add(id1,id2,0);add(x,id2,1);
		add(y,id1,1);
	}
	spfa(1);
	if(dis[n]>1e7) puts("-1");
	else cout<<dis[n]/2;
	return 0;
}