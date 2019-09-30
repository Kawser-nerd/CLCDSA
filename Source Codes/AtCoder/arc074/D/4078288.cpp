#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxN = 205,maxM=2e6+5;
const int inf = 1e9;

struct edge
{
	int fr, to, nxt;
	int c, f;
} graph[maxM];
int head[maxN];
int totlen;
int level[maxN];
int n, m;
int s, t;

bool dinic_bfs()
{
	memset(level, 0, sizeof(level));
	queue<int> que;
	que.push(s);
	level[s] = 1;
	while (!que.empty())
	{
		int u = que.front(); que.pop();
		for (int i = head[u]; i != -1; i = graph[i].nxt)
		{
			int v = graph[i].to;
			if (!level[v] && graph[i].c > graph[i].f)
			{
				level[v] = level[u] + 1;
				que.push(v);
			}
		}
	}
	return level[t] != 0;
}

int dinic_dfs(int u, int cpflow)
{
	if (u == t) return cpflow;
	int addflow = 0;
	for (int i = head[u]; i != -1 && addflow < cpflow; i = graph[i].nxt)
	{
		int v = graph[i].to;
		if (level[u] + 1 == level[v] && graph[i].c > graph[i].f)
		{
			int tmpadd = dinic_dfs(v, min(cpflow - addflow, graph[i].c - graph[i].f));
			graph[i].f += tmpadd;
			graph[i ^ 1].f -= tmpadd;
			addflow += tmpadd;
		}
	}
	return addflow;
}

int dinic()
{
	int maxflow = 0;
	while (dinic_bfs())
		maxflow += dinic_dfs(s, inf);
	return maxflow;
}

void addEdge(int u, int v, int c, int i)
{
	graph[totlen].to = v;
	graph[totlen].fr = u;
	graph[totlen].nxt = head[u];
	graph[totlen].c = c;
	graph[totlen].f = 0;
	head[u] = totlen++;
	graph[totlen].to = u;
	graph[totlen].fr = v;
	graph[totlen].nxt = head[v];
	graph[totlen].c = 0;
	graph[totlen].f = 0;
	head[v] = totlen++;
}

void init()
{
	for (int i = 0; i <= n + 5; i++)
		head[i] = -1;
	totlen = 0;
}

int main()
{
	int h,w,sk,sl,tk,tl;
	char ch[105];
	scanf("%d%d",&h,&w);
	n=h+w+2;
	s=0;
	t=h+w+1;
	init();
	for(int i=1;i<=h;i++)
    {
        scanf("%s",ch+1);
        for(int l=1;l<=w;l++)
        {
            if(ch[l]=='o')
            {
                addEdge(i,h+l,1,0);
                addEdge(h+l,i,1,0);
            }
            if(ch[l]=='S')
            {
                sk=i;sl=l;
                addEdge(s,i,inf,0);
                addEdge(s,h+l,inf,0);
            }
            if(ch[l]=='T')
            {
                tk=i;tl=l;
                addEdge(i,t,inf,0);
                addEdge(h+l,t,inf,0);
            }
        }
    }
    if(sk==tk||sl==tl)printf("-1");
	else printf("%d\n",dinic());
	return 0;
}