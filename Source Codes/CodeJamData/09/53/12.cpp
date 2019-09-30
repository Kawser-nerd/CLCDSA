#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 1005
#define maxm 2000005

int x[maxn],y[maxn];
int head[maxn],heap[maxn],l[maxn],hz,Link[maxn];
int vtx[maxm],next[maxm],tot,n,m,A[maxn],color[maxn];
bool map[maxn][maxn],mark[maxn];

inline void Add(int a,int b)
{
	vtx[tot]=b;
	next[tot]=head[a];
	head[a]=tot++;
	map[a][b]=true;
}

inline void sink(int x)
{
	int mid=x*2;
	while (mid<=hz)
	{
		if (mid+1<=hz && l[heap[mid+1]]>l[heap[mid]]) ++mid;
		if (l[heap[x]]<l[heap[mid]]) 
		{
			swap(Link[heap[x]],Link[heap[mid]]);
			swap(heap[x],heap[mid]);
		}else break;
		x=mid;
		mid=x*2;
	}
}

inline void up(int x)
{
	for (int mid=x/2;mid;mid=x/2)
	{
		if (l[heap[mid]]<l[heap[x]])
		{
			swap(Link[heap[x]],Link[heap[mid]]);
			swap(heap[x],heap[mid]);
		}else break;
		x=mid;
	}
}

int main()
{
	freopen("C_small1.in","r",stdin);
	freopen("C_small1.out","w",stdout);
	
	int T,test=1;
	for (scanf("%d",&T);test<=T;++test)
	{
		scanf("%d",&n);
		for (int i=0;i<n;++i)
			scanf("%d%d",&x[i],&y[i]);
		tot=2;
		memset(map,false,sizeof(map));
		memset(head,0,sizeof(head));
		
		x[n]=100000;
		
		for (int i=0;i<n;++i)
		{
			int u=n,v=n,w=n;
			for (int j=0;j<n;++j)
			if (x[i]<x[j])
			{
				if (y[j]==y[i]+1 && x[j]<x[u]) u=j;
				if (y[j]==y[i] && x[j]<x[v]) v=j;
				if (y[j]==y[i]-1 && x[j]<x[w]) w=j;
			}
			if (u!=n) Add(i,u),Add(u,i);
			if (v!=n) Add(i,v),Add(v,i);
			if (w!=n) Add(i,w),Add(w,i);
		}

//		printf("%d\n",(tot-2)/2);
		memset(l,0,sizeof(l));
		hz=0;
		for (int i=0;i<n;++i)
		{
			Link[i]=++hz;
			heap[hz]=i;
		}
		int ans=0;
		for (int i=n;i>0;--i)
		{
			int v=-1;
			int u=heap[1];
			
			memset(mark,false,sizeof(mark));
			for (int p=head[u];p;p=next[p])
			if (Link[vtx[p]]==-1)
				mark[color[vtx[p]]]=true;
			for (color[u]=0;mark[color[u]];++color[u]);
			ans=max(ans,color[u]+1);
			
			Link[u]=-1;
			Link[heap[hz]]=1;
			heap[1]=heap[hz--];
			sink(1);
			for (int p=head[u];p;p=next[p])
			if (Link[vtx[p]]!=-1)
			{
				++l[vtx[p]];
				up(Link[vtx[p]]);
			}else
			{
				if (v==-1) v=vtx[p];
				else
				{
					if (!map[v][vtx[p]]) 
					{
//						printf("Imperfect\n");
//						goto answer;
					}
				}
			}
		}
		printf("Case #%d: %d\n",test,ans);
answer:;
	}
	return 0;
}
