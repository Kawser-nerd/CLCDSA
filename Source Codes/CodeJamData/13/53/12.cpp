#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

typedef pair<int,int> pii;

int eu[2048], ev[2048], ea[2048], eb[2048];
int ne[1024];

int n, m, p;

vector<int> g[1024];

bool us[1024];
int pa[1024];

vector<int> nodes;

long long di[1024];
int fl[1024];
priority_queue< pii, vector<pii>, greater<pii> > pq;

bool ok( int la )
{
	pii a;
	int i, j, k, v, u, le, o;
	memset( di, 63, sizeof( di ) );
	
	while ( pq.size() )
		pq.pop();

	di[1] = 0;
	pq.push( make_pair( 0, 1 ) );

	while ( pq.size() )
	{
		a = pq.top();
		pq.pop();
		v = a.second;
		//printf( "DD %d %lld %d %d\n", v, di[v], ne[v], fl[v] );
		if ( v == 2 )
			break;
		k = a.first;
		if ( k > di[v] )
			continue;
		
		if ( us[v] && v != 1 && !fl[v] )
		{
			//printf( "RET %d %d\n", la, v );
			return 0;
		}
		
		for ( i = 0; i < (int) g[v].size(); i++ )
		{
			j = g[v][i];
			u = ev[j];
			
			if ( ne[v] == -1 )
			{
				if ( fl[v] )
				{
					if ( v == *nodes.rbegin() || fl[v] == 2 )
						o = 2;
					else o = 0;
					le = ea[j];
				}
				else
				{
					le = eb[j];
					o = 0;
				}
			}
			else
			{
				if ( u == ne[v] )
				{
					o = 1;
					le = ea[j];
				}
				else
				{
					le = eb[j];
					o = 0;
				}
			}

			if ( o )
			{
				if ( di[u] >= di[v] + le )
				{
					fl[u] = o;
					if ( di[u] > di[v] + le )
					{
						di[u] = di[v] + le;
						pq.push( make_pair( di[u], u ) );
					}
				}
			}
			else
			{
				if ( di[u] > di[v] + le )
				{
					fl[u] = 0;
					di[u] = di[v] + le;
					pq.push( make_pair( di[u], u ) );
				}
			}
		}
	}
	return fl[2];
}

int main()
{
	int i, j;
	int t, T;
	scanf( "%d", &T );
	for ( t = 1; t <= T; t++ )
	{
		scanf( "%d %d %d", &n, &m, &p );
		for ( i = 0; i <= n; i++ )
			g[i].clear();
		for ( i = 1; i <= m; i++ )
		{
			scanf( "%d %d %d %d", &eu[i], &ev[i], &ea[i], &eb[i] );
			j = eu[i];
			g[j].push_back( i );
		}
		
		for ( i = 1; i <= p; i++ )
		{
			scanf( "%d", &pa[i] );
		}
		memset( us, 0, sizeof( us ) );
		us[ 1 ] = 1;
		nodes.clear();
		j = 1;
		memset( ne, -1, sizeof( ne ) );
		for ( i = 1; i <= p; i++ )
		{
			if ( eu[pa[i]] == 2 )
				break;
			if ( us[ ev[ pa[i] ] ] )
			{
				break;
			}
			ne[ eu[ pa[i] ] ] = ev[pa[i]];
			us[ ev[ pa[i] ] ] = 1;
			nodes.push_back( ev[ pa[i] ] );
			if ( !ok( i ) )
				break;
		}
		if ( i <= p )
			printf( "Case #%d: %d\n", t, pa[i] );
		else
			printf( "Case #%d: Looks Good To Me\n", t );
	}
	return 0;
}
