#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

const int maxn = 1000 + 10;

pair<int,int> p2[maxn];

int deg[maxn],g[maxn][maxn];
int y[maxn];
int hash[maxn];
int n;

void prepare()
{
	for(int i=0;i<n;i++) deg[i] = 0;
	for(int i=0;i<=35;i++) hash[i] = n;

	for(int i=n-1;i>=0;i--)
	{
		for(int j=y[i]-1;j<=y[i]+1;j++) if( hash[j]!=n )
			g[i][ deg[i]++ ] = hash[j];
		hash[ y[i] ] = i;
	}
}
bool can1()
{
	for(int i=0;i<n;i++) if( deg[i] ) return false;
	return true;
}

bool e[maxn][maxn];
int ty[maxn];
bool valid;
void dfs( int x,int t )
{
	if( ty[x]!=3 )
	{
		if( t!=ty[x] ) valid = false;
		return;
	}

	ty[x] = t;
	for(int i=0;i<n;i++) if( e[x][i] ) dfs(i,3-t);
}
bool can2()
{
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++) e[i][j] = false;
	for(int i=0;i<n;i++)
	for(int j=0;j<deg[i];j++)
		e[i][ g[i][j] ] = e[g[i][j]][i] = true;

	for(int i=0;i<n;i++) ty[i] = 3;
	valid = true;
	for(int i=0;i<n;i++) if(ty[i]==3) dfs(i,1);
	return valid;
}

int a[maxn];
inline int find( int x )
{
	if( a[x]<0 ) return x;else return a[x]=find(a[x]);
}

int lab[maxn],tot;
void build()
{
	tot = 0;
	for(int i=0;i<n;i++) if( find(i)==i ) lab[i] = ++tot;
	for(int i=0;i<n;i++) lab[i] = lab[find(i)];
	
	for(int i=1;i<=tot;i++)
	for(int j=1;j<=tot;j++) e[i][j] = false;

	for(int i=0;i<n;i++)
	for(int j=0;j<deg[i];j++)
		e[lab[i]][ lab[g[i][j]] ] = e[lab[g[i][j]]][lab[i]] = true;
}

set< pair<int,int> > bst[4];

int range[maxn];
int bit[8];


inline void insert( int x )
{
	bst[ bit[range[x]] ].insert( make_pair( -deg[x],x ) );
}
inline void del( int x )
{
	bst[ bit[range[x]] ].erase( make_pair( -deg[x],x ) );
}
int enlarge( int x )
{
	range[x] = 7;insert(x);
	for(int i=0;i<deg[x];i++) if( range[ g[x][i] ]==0 ) enlarge( g[x][i] );
}
int Dtmp[maxn][maxn];
bool vis[maxn];
void dfs(int dep)
{
	int md = 0;while( md<4 && bst[md].empty() ) md++;
	if(md==4)
	{
		valid = true;
		return;
	}

	int x = bst[md].begin()->second;
	int *tmp = Dtmp[dep];
	int c;
	vis[x] = false;del(x);
	for( int u = range[x];u;u-=c )
	{
		c = (u&(-u));
		for(int j=0;j<deg[x];j++) if( vis[ g[x][j] ] )
		{
			#define Y g[x][j]
			tmp[Y] = range[Y];
			del(Y);
			range[Y]&=(7-c);
			insert(Y);
			#undef Y
		}
		
		dfs(dep+1);
		if(valid) return;

		for(int j=0;j<deg[x];j++) if( vis[ g[x][j] ] )
		{
			#define Y g[x][j]
			del(Y);
			range[Y] = tmp[Y];
			insert(Y);
			#undef Y
		}

		if( dep==1 ) break;
	}
	vis[x] = true;insert(x);
}
bool solve3()
{
	for(int i=1;i<=tot;i++) deg[i] = 0;
	for(int i=1;i<=tot;i++)
	for(int j=1;j<=tot;j++) if(e[i][j]) g[i][ deg[i]++ ] = j;

	for(int i=1;i<=tot;i++) range[i] = 0;
	for(int i=1;i<=tot;i++) vis[i] = true;

	for(int i=1;i<=tot;i++) if( range[i] == 0 )
	{
		for(int j=0;j<4;j++) bst[j].clear();
		enlarge(i);
		valid = false;
		dfs(1);
		if(!valid) return false;
	}
	return true;
}
bool can3()
{
	int md = 0;
	for(int i=0;i<n;i++) md = max(md,deg[i]);
	if( md < 3 ) return true;

	for(int i=0;i<n;i++) a[i] = -1;
	
	for(int i=0;i<n;i++) if(deg[i]==3)
	{
		int ri = find( g[i][0] );
		int rj = find( g[i][2] );
		if( ri!=rj ) a[ri] = rj;
	}

	build();
	for(int i=1;i<=tot;i++) if(e[i][i]) return false;

	return solve3();
}
int solve()
{
	prepare();
	if( can1() ) return 1;
	if( can2() ) return 2;
	if( can3() ) return 3;
	return 4;
}
int main()
{
	for(int i=0;i<8;i++)
	for(int j=1;j<8;j*=2) if(i&j) bit[i]++;

	int T;
	scanf("%d",&T);
	for(int num=1;num<=T;num++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d%d",&p2[i].first,&p2[i].second);
		sort( p2,p2+n );
		for(int i=0;i<n;i++) y[i] = p2[i].second;
		printf("Case #%d: %d\n",num,solve());
	}
	return 0;
}
