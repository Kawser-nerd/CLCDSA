#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2005,MAXM=4005;
int n,k,ncnt=0;
bool vis[MAXN];
struct edge
{
	int v,nxt;
	edge(){}
	edge(int vv,int nn)
	{
		v=vv,nxt=nn;
	}
}E[MAXM];
int w[MAXN];
void addedge(int u,int v)
{
	E[++ncnt]=edge(v,w[u]);
	w[u]=ncnt;
}
int dfs1(int u,int f,int d)
{
	int re=1;
	if(d==0)
		return re;
	for(int i=w[u];i;i=E[i].nxt)
	{
		int v=E[i].v;
		if(v!=f)
		{
			re+=dfs1(v,u,d-1);
		}
	}
	return re;
}
int dfs2(int u,int f,int d)
{
	int re=0;
	if(d==0)
		return 1;
	for(int i=w[u];i;i=E[i].nxt)
	{
		int v=E[i].v;
		if(v!=f)
		{
			re+=dfs2(v,u,d-1);
		}
	}
	return re;
}
int main()
{
	//freopen("shorten.in","r",stdin);
	//freopen("shorten.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	int zans=0;
	for(int i=1;i<=n;i++)
	{
		int o=dfs1(i,0,(k/2));
		if(k&1)
		{
			int op=0;
			for(int j=w[i];j;j=E[j].nxt)
				op=max(op,dfs2(E[j].v,i,k/2));
			o+=op;
		}
		zans=max(zans,o);
	}
	printf("%d\n",n-zans);
	fclose(stdin);
	fclose(stdout);;
}