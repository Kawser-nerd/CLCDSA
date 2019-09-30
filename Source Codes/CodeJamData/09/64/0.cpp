#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

//BEGINTEMPLATE_BY_ACRUSH_TOPCODER
#define SIZE(X) ((int)(X.size()))//NOTES:SIZE(
#define LENGTH(X) ((int)(X.length()))//NOTES:LENGTH(
#define MP(X,Y) make_pair(X,Y)//NOTES:MP(
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
#define two(X) (1<<(X))//NOTES:two(
#define twoL(X) (((int64)(1))<<(X))//NOTES:twoL(
#define contain(S,X) (((S)&two(X))!=0)//NOTES:contain(
#define containL(S,X) (((S)&twoL(X))!=0)//NOTES:containL(


//CORRECTNESS: **********

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
 
using namespace std;

const int maxnode=20000+5;
const int maxedge=2000000+5;
const int oo=1000000000;

int node,src,dest,nedge;
int head[maxnode],point[maxedge],next[maxedge],flow[maxedge],capa[maxedge];
int dist[maxnode],Q[maxnode],work[maxnode];

void init(int _node,int _src,int _dest)
{
	node=_node;
	src=_src;
	dest=_dest;
	for (int i=0;i<node;i++) head[i]=-1;
	nedge=0;
}
void addedge(int u,int v,int c1,int c2)
{
	point[nedge]=v,capa[nedge]=c1,flow[nedge]=0,next[nedge]=head[u],head[u]=(nedge++);
	point[nedge]=u,capa[nedge]=c2,flow[nedge]=0,next[nedge]=head[v],head[v]=(nedge++);
}
bool dinic_bfs()
{
	for (int i=0;i<node;i++) dist[i]=-1;
	dist[src]=0;
	int sizeQ=0;
	Q[sizeQ++]=src;
	for (int cl=0;cl<sizeQ;cl++)
		for (int k=Q[cl],i=head[k];i>=0;i=next[i])
			if (flow[i]<capa[i] && dist[point[i]]<0)
			{
				dist[point[i]]=dist[k]+1;
				Q[sizeQ++]=point[i];
			}
	return dist[dest]>=0;
}
int dinic_dfs(int x,int exp)
{
	if (x==dest) return exp;
	for (int &i=work[x];i>=0;i=next[i])
	{
		int v=point[i],tmp;
		if (flow[i]<capa[i] && dist[v]==dist[x]+1 && (tmp=dinic_dfs(v,min(exp,capa[i]-flow[i])))>0)
		{
			flow[i]+=tmp;
			flow[i^1]-=tmp;
			return tmp;
		}
	}
	return 0;
}
int dinic_flow()
{
	int result=0;
	while (dinic_bfs())
	{
		for (int i=0;i<node;i++) work[i]=head[i];
		while (1)
		{
			int delta=dinic_dfs(src,oo);
			if (delta==0) break;
			result+=delta;
		}
	}
	return result;
}

const int maxn=500+5;

int n;
int X[maxn],Y[maxn],R[maxn],S[maxn];

int sqr(int x)
{
	return x*x;
}
int main()
{
//	freopen("D.in","r",stdin);
//	freopen("D-small-attempt0.in","r",stdin);freopen("D-small-attempt0.out","w",stdout);
//	freopen("D-small-attempt1.in","r",stdin);freopen("D-small-attempt1.out","w",stdout);
//	freopen("D-small-attempt2.in","r",stdin);freopen("D-small-attempt2.out","w",stdout);
	freopen("D-large.in","r",stdin);freopen("D-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		printf("Case #%d:",caseId);
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%d%d%d%d",&X[i],&Y[i],&R[i],&S[i]);
		init(n+n+2,n+n,n+n+1);
		int P=0;
		int oo=10000000;
		for (int i=0;i<n;i++)
		{
			addedge(i,i+n,oo,oo);
			if (S[i]>0)
			{
				P+=S[i];
				addedge(src,i,S[i],0);
			}
			else
			{
				addedge(i,dest,-S[i],0);
			}
		}
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				if (i!=j && sqr(X[i]-X[j])+sqr(Y[i]-Y[j])<=sqr(R[i]))
					addedge(i,j+n,oo,0);
		int D=dinic_flow();
		printf(" %d\n",P-D);
		fflush(stdout);
	}
	return 0;
}