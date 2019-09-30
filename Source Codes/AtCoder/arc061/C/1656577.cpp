#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<vector>
#define pa pair<int,int>
 
using namespace std;

const int MAXN=1000010;
int dis[MAXN];
vector <pa> g[MAXN];
vector <int> new_g[MAXN],all[MAXN];
int visit[MAXN],ptr[MAXN];
queue <int> q;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		u--,v--;
		g[u].push_back(make_pair(c,v));
		g[v].push_back(make_pair(c,u));
		all[c].push_back(u);
		all[c].push_back(v);
	}
	for (int i=0;i<n;i++)
	{
		sort(g[i].begin(),g[i].end());
		visit[i]=-1;
	}
	int newn=n;
	for (int i=0;i<MAXN;i++)
	{
		if (all[i].empty())
		{
			continue;
		}
		for (int it=0;it<all[i].size();it++)
		{
			int v=all[i][it];
			if (visit[v]==i)
			{
				continue;
			}
			q.push(v);
			visit[v]=i;
			while (!q.empty())
			{
				int x=q.front();
				q.pop();
				while (ptr[x]<(int)g[x].size())
				{
					int c=g[x][ptr[x]].first;
					if (c!=i)
					{
						break;
					}
					int u=g[x][ptr[x]].second;
					if (visit[u]!=i)
					{
						visit[u]=i;
						q.push(u);
					}
					ptr[x]++;
				}
				new_g[x].push_back(newn);
				new_g[newn].push_back(x);	
			}
			newn++;
		}
	}
	for (int i=0;i<newn;i++)
	{
		dis[i]=-2;
	}
	q.push(0);
	dis[0]=0;
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		for (int i=0;i<new_g[x].size();i++)
		{
			int u=new_g[x][i];
			if (dis[u]==-2)
			{
				dis[u]=dis[x]+1;
				q.push(u);	
			}
		}
	}
	cout<<dis[n-1]/2;
    return 0;
}