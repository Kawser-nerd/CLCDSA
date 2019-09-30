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
char f[5][5];
int d[70000][20];
int lm;

int calc( int x, int y ) 
{
	if( x < 0 || y < 0 || x >= n || y >= m ) return -1;
	return x * m + y; 
}

bool rec( int mask, int id )
{
	if( id == -1 ) return true;
	int & ret = d[mask][id];
	if( mask & ( 1 << id ) ) return true;
	if( ret ) return ret == 1;
	mask |= ( 1 << id );

	ret = -1;
	int x = id / m;
	int y = id % m;
	for( int dx = -1; dx <= 1; ++ dx )
		for( int dy = -1; dy <= 1; ++ dy )
			if( !rec( mask, calc( x + dx, y + dy ) ) ) ret = 1;

	return ret == 1;
}

int main( )
{
	int i, j, k, t, tt;

	freopen( "in.txt", "r", stdin );
	freopen( "out.txt", "w", stdout );

	scanf( "%d", &t );
	for( tt = 1; tt <= t; ++ tt )
	{
		scanf( "%d %d", &n, &m );
		fi( n ) scanf( "%s", f[i] );
		int id = 0, st = 0;
		int mask = 0;
		fi( n ) fj( m )
		{
			if( f[i][j] == 'K' ) st = id;
			else if( f[i][j] == '#' ) mask |= ( 1 << id );
			++ id;
		}
		lm = ( 1 << id ) - 1;
		printf( "Case #%d: ", tt );
		memset( d, 0, sizeof( d ) );
		if( rec( mask, st ) ) printf( "A" );
		else printf( "B" );
		printf( "\n" );
	}

	return 0;
}
