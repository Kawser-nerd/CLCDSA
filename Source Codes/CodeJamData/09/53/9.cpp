#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define oo 1005
int test,n,x[oo],y[oo],d[oo],q[oo],c[oo];
bool dist[oo][oo],visit[oo];

inline void Readin()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
}

inline void Prepare()
{
	memset(dist,0,sizeof(dist));
	x[0]=100000;
	for (int i=1;i<=n;i++)
	{
		int u=0,v=0,w=0;
		for (int j=1;j<=n;j++)
		if (x[i]<x[j]) 
		{
			if (y[j]==y[i]+1 && x[j]<x[u]) u=j;
			if (y[j]==y[i] && x[j]<x[v]) v=j;
			if (y[j]==y[i]-1 && x[j]<x[w]) w=j;
		}
		dist[i][u]=dist[u][i]=1;
		dist[i][v]=dist[v][i]=1;
		dist[i][w]=dist[w][i]=1;
	}
}

inline void Work()
{
	memset(visit,0,sizeof(visit));
	memset(d,0,sizeof(d));d[0]=-1;
	for (int i=1;i<=n;i++)
	{
		int k=0;
		for (int j=1;j<=n;j++)
			if (!visit[j] && d[j]>d[k])
				k=j;
		visit[k]=1;q[i]=k;
		for (int j=1;j<=n;j++)
			if (dist[j][k]) ++d[j];
	}
	memset(c,0,sizeof(c));
	int ret=0;
	for (int i=1;i<=n;i++) 
	{
		int k=q[i];
		memset(visit,0,sizeof(visit));
		for (int j=1;j<=n;j++)
			if (dist[j][k] && c[j])
				visit[c[j]]=1;
		for (c[k]=1;visit[c[k]];c[k]++);
			ret>?=c[k];
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (dist[i][j] && c[i]==c[j])
			{
				printf("xxx\n");
			}
	printf("%d\n",ret);
}

int main()
{
	int Case=0;
	for (scanf("%d",&test);test;--test)
	{
		printf("Case #%d: ",++Case);
		Readin();
		Prepare();
		Work();
	}
	
	return 0;
}
