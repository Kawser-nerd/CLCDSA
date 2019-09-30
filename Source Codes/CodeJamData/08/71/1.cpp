#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <assert.h>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>

using namespace std;

#define fo(a,b,c) for( a = (b); a < (c); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, (a) )
#define fj(a) fr( j, (a) )
#define fk(a) fr( k, (a) )
#define all(v) (v).begin( ), (v).end( )
#define pb push_back
#define mp make_pair

int n, m;
vector< int > g[1005];
char buf[1005];
map< string, int > mm;
int cnt = 0;

int getid( )
{
	scanf( "%s", buf );
	if( buf[0] >= 'a' && buf[0] <= 'z' ) return -1;

	if( mm.find( buf ) != mm.end( ) ) return mm[buf];
	mm[buf] = cnt ++;
	return cnt - 1;
}

int rec( int id )
{
	int i;
	int cur = 0;
	vector< int > moo;
	fi( g[id].size( ) ) moo.pb( rec( g[id][i] ) );

	sort( all( moo ) );
	for( int i = moo.size( ) - 1; i >= 0; -- i )
	{
		cur = max( cur, moo[i] + (int)moo.size( ) - i - 1 );
	}
	cur = max( cur, (int)moo.size( ) + 1 );

	return cur;
}

int main( )
{
	int i, j, k, t, tt;

	freopen( "in.txt", "r", stdin );
	freopen( "out.txt", "w", stdout );

	scanf( "%d", &t );
	for( tt = 1; tt <= t; ++ tt )
	{
		cnt  = 0;
		mm.clear( );
		scanf( "%d", &n );
		fi( n ) g[i].clear( );
		fi( n )
		{
			int cur;
			cur = getid( );
			scanf( "%d", &k );
			fj( k )
			{
				int a = getid( );
				if( a != -1 ) g[cur].pb( a );
			}
		}
		printf( "Case #%d: ", tt );
		printf( "%d", rec( 0 ) );
		printf( "\n" );
	}

	return 0;
}
