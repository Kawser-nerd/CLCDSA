#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>

#define fo(a,b,c) for( a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )

using namespace std;

int dx[4] = { -1, -1, -1, 0 };
int dy[4] = { -1, 0, 1, -1 };

int n, m;
char s[105][105];
int v[105][105][4];

int main( )
{
	int i, j, k, t, tt;

	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );

	scanf( "%d\n", &tt );
	for( t = 1; t <= tt; ++ t )
	{
		printf( "Case #%d:", t );

		scanf( "%d %d", &n, &m );
		fi( n ) scanf( "%s", s[i] );

		fi( n )
		{
			int pos = n - 1;
			for( j = n - 1; j >= 0; -- j )
			{
				if( s[i][j] != '.' ) s[i][pos --] = s[i][j];
			}
			for( pos; pos >= 0; -- pos ) s[i][pos] = '.';
		}
		bool ok1 = false, ok2 = false;
		_( v, 0 );
		fi( n ) fj( n ) fk( 4 )
		{
			if( s[i][j] == 'R' )
			{
				v[i][j][k] = 1;
				if( i + dx[k] >= 0 && j + dy[k] >= 0 ) v[i][j][k] += v[i + dx[k]][j + dy[k]][k];
				if( v[i][j][k] == m ) ok1 = true;
			}
		}
		_( v, 0 );
		fi( n ) fj( n ) fk( 4 )
		{
			if( s[i][j] == 'B' )
			{
				v[i][j][k] = 1;
				if( i + dx[k] >= 0 && j + dy[k] >= 0 ) v[i][j][k] += v[i + dx[k]][j + dy[k]][k];
				if( v[i][j][k] == m ) ok2 = true;
			}
		}

		if( !ok1 && !ok2 ) printf( " Neither\n" );
		else if( ok1 && ok2 ) printf( " Both\n" );
		else if( ok1 ) printf( " Red\n" );
		else if( ok2 ) printf( " Blue\n" );
	}

	return 0;
}
