#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 400 + 10;
const int BITSIZE = 20;
const int BITGR = 20;
const int INF = 10000000;

int dset[maxn][BITGR];
int d[maxn];
int F[maxn];

int f[maxn][maxn];
int q[maxn];
bool g[maxn][maxn];
int gset[maxn][BITGR];
int n,m,l,r;
int one[ 1<<BITSIZE ];
int ans,tmp;

inline void empty( int *a)
{
	for( int i = 0;i<BITGR;i++ ) a[i] = 0;
}
inline void add( int *a,int x )
{
	a[ x/20 ] |= (1<<(x%20));
}


int bef[maxn],bt;
int aft[maxn],at;

void work()
{
	d[0] = 0;
	for(int i=1;i<n;i++) d[i] = INF;

	for( int i = 0;i<=n;i++ ) empty(dset[i]);

	for( int i = 0;i<n;i++ ) empty(gset[i]);
	for( int i = 0;i<n;i++ )
	for( int j = 0;j<n;j++ ) if( g[i][j] )
		add( gset[i],j );
	
	l = 0;r = 1;q[1] = 0;
	int x;
	while( l<r )
	{
		x = q[++l];add( dset[d[x]],x );
		for( int i = 0;i<n;i++ ) if( d[x]+1 < d[i] && g[x][i] )
		{
			d[i] = d[x] + 1;
			q[++r] = i;
		}
	}

	for( int i = 0;i<n;i++ )
	for( int j = 0;j<n;j++ ) f[i][j] = -INF;


	int *p1,*p2,*p3,*p4;
	empty(gset[1]);

	ans = 0;
	for( int t = 1;t<=r;t++ )
	{
		x = q[t];
		bt = at = 0;
		for( int i = 0;i<n;i++ ) if( d[i]==d[x]-1 && g[i][x] )
			bef[bt++] = i;

		for( int i = 0;i<n;i++ ) if( d[i]==d[x]+1 && g[i][x] )
			aft[at++] = i;

		if( t==1 )
		{
			for( int i = 0;i<at;i++ ) f[x][ aft[i] ] = 0;
		}else
		if( x==1 )
		{
			for( int i = 0;i<bt;i++ )
			{
				// bef[i],x
				tmp = f[bef[i]][x];	
				// ( g[bef[i]]) & dset[d[x]]
				p1 = gset[bef[i]];
				p3 = dset[d[x]];

				for( int j = 0;j<BITGR;j++ )
					tmp+= one[ p1[j]&p3[j] ];

				ans = max( ans,tmp );
			}
			break;
		}else
		{
			for( int i = 0;i<bt;i++ ) if( f[bef[i]][x] >=0 )
			for( int j = 0;j<at;j++ )
			{
				tmp = f[bef[i]][x];
				// ( g[aft[j]]|g[x]|g[bef[i]]) & dset[d[x]]
				p1 = gset[aft[j]];
				p2 = gset[x];
				p3 = gset[bef[i]];
				p4 = dset[d[x]];

				for( int k = 0;k<BITGR;k++ )
					tmp+=one[ (p1[k]|p2[k]|p3[k])&p4[k] ];

				f[x][ aft[j] ] = max( f[x][ aft[j] ] , tmp-1 );
			}

		}
	}
	
}
int main()
{
	for( int i = 1;i<(1<<BITSIZE);i++ )
		one[i] = one[i/2] + (i&1);

	int T=0,TT;

	int x,y;
	for( scanf("%d",&TT);TT;TT-- )
	{
		scanf("%d%d",&n,&m);
		for( int i = 0;i<n;i++ )
		for( int j = 0;j<n;j++ ) g[i][j] = false;

		while(m--)
		{
			scanf("%d,%d",&x,&y);
			g[x][y] = g[y][x] = true;
		}

		work();
		printf("Case #%d: %d %d\n",++T,d[1]-1,ans);
	}
	return 0;
}
