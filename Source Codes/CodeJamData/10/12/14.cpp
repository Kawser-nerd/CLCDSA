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

const int maxn = 1005;

int n, m, del, ins;
int a[maxn];
int d[maxn][300];

int main( )
{
	int i, j, k, t, tt;

	freopen( "input.txt", "r", stdin );
//	freopen( "output.txt", "w", stdout );

	scanf( "%d\n", &tt );
	for( t = 1; t <= tt; ++ t )
	{
		printf( "Case #%d:", t );
		scanf( "%d %d %d %d", &del, &ins, &m, &n );
		fi( n ) scanf( "%d", &a[i] );
		_( d, 0 );
		int ans = 1000000000;
		fi( 300 )
		{
			d[0][i] = min( del, abs( a[0] - i ) );
			if( n == 1 ) ans = min( ans, d[0][i] );
		}
		fi( n ) if( i )
		{
			fj( 260 )
			{
				d[i][j] = d[i - 1][j] + del;
				fk( 260 )
				{
					if( j != k && !m ) continue;
					int val = d[i - 1][k] + abs( j - a[i] );
					if( j != k ) val += ins * ( ( abs( j - k ) - 1 ) / m ); 
					d[i][j] = min( d[i][j], val );
				}
				if( i == n - 1 ) ans = min( ans, d[i][j] );
			}
		}
		printf( " %d\n", ans );
	}

	return 0;
}
