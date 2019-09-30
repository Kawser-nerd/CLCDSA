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

const int maxnode=20000*2+5;
const int maxedge=1000000+5;
const int oo=1000000000;

int node,src,dest,nedge;
int head[maxnode],point[maxedge],next[maxedge],flow[maxedge],capa[maxedge];
int dist[maxnode],Q[maxnode],work[maxnode];

void init(int _node,int _src,int _dest)
{
	node=_node;
	src=_src-1;
	dest=_dest-1;
	for (int i=0;i<node;i++) head[i]=-1;
	nedge=0;
}
void addedge(int u,int v,int c1,int c2)
{
//	printf("%d %d %d %d\n",u,v,c1,c2);
	u--;v--;
	point[nedge]=v,capa[nedge]=c1,flow[nedge]=0,next[nedge]=head[u],head[u]=(nedge++);
	point[nedge]=u,capa[nedge]=c2,flow[nedge]=0,next[nedge]=head[v],head[v]=(nedge++);
}
bool dinic_bfs()
{
	memset(dist,255,sizeof(dist));
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


const int maxsize=50+5;
const int MX[]={-1,1,0,0};
const int MY[]={0,0,-1,1};

int n,sizeX,sizeY;
char A[maxsize][maxsize];

int ID(int x,int y)
{
	return (x-1)*sizeY+y;
}
int main()
{
//	freopen("..\\E.in","r",stdin);
//	freopen("..\\E-small-attempt0.in","r",stdin);freopen("..\\E-small-attempt0.ans","w",stdout);
//	freopen("..\\E-small-attempt1.in","r",stdin);freopen("..\\E-small-attempt1.out","w",stdout);
	freopen("..\\E-large.in","r",stdin);freopen("..\\E-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	srand(1028);
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		printf("Case #%d: ",caseId);
		scanf("%d%d",&sizeX,&sizeY);
		for (int i=1;i<=sizeX;i++)
			scanf("%s",A[i]+1);
		int result=0;
		for (int i=1;i<=sizeX;i++) for (int j=1;j<=sizeY;j++)
			if (A[i][j]=='#')
				result+=4;
		init(sizeX*sizeY+2,sizeX*sizeY+1,sizeX*sizeY+2);
		for (int i=1;i<=sizeX;i++) for (int j=1;j<=sizeY;j++)
			for (int d=0;d<4;d++)
			{
				int x=i+MX[d],y=j+MY[d];
				if (x>=1 && x<=sizeX && y>=1 && y<=sizeY)
				{
					if (A[i][j]=='#' && A[x][y]=='#') result--;
					if ((i+j)%2==0 && A[i][j]=='?' && A[x][y]=='?')
						addedge(ID(i,j),ID(x,y),2,0);
				}
			}
		int TS=0;
		for (int i=1;i<=sizeX;i++) for (int j=1;j<=sizeY;j++)
			if (A[i][j]=='?')
			{
				int S=4;
				for (int d=0;d<4;d++)
				{
					int x=i+MX[d],y=j+MY[d];
					if (x>=1 && x<=sizeX && y>=1 && y<=sizeY && A[x][y]=='#')
						S-=2;
				}
				if (S<=0) continue;
				TS+=S;
				if ((i+j)%2==0)
					addedge(sizeX*sizeY+1,ID(i,j),S,0);
				else
					addedge(ID(i,j),sizeX*sizeY+2,S,0);
			}
		int flow=dinic_flow();
		result+=(TS-flow);
		printf("%d\n",result);
		fflush(stdout);
	}
	return 0;
}

//ENDSOURCECODE_BY_ACRUSH_TOPCODER

