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
vector< int > moo;
int a[1005];

int mod( int a )
{
	int m = 10007;
	return ( a % m + m ) % m;
}

int main( )
{
	int i, j, k, t, tt;

	freopen( "in.txt", "r", stdin );
	freopen( "out.txt", "w", stdout );

	scanf( "%d", &t );
	for( tt = 1; tt <= t; ++ tt )
	{
		scanf( "%d", &n );
		fi( n ) scanf( "%d", &a[i] );
		moo.clear( );
		fk( 1024 )
		{
			bool ok = true;
			fj( n ) if( j )
			{
				i = k + j;
				int id = 1;
				while( ( i & 1 ) == 0 )
				{
					++ id;
					i /= 2;
				}

				int jj = j - ( 1 << id );
				if( jj > 0 && mod( a[j] - a[j - 1] ) != mod( a[jj] - a[jj - 1] ) )
				{
					ok = false;
					break;
				}
			}

			if( ok )
			{
				i = k + n;
				int id = 1;
				while( ( i & 1 ) == 0 )
				{
					++ id;
					i /= 2;
				}

				int jj = j - ( 1 << id );
				if( jj > 0 )
				{
					moo.pb( mod( a[n - 1] + a[jj] - a[jj - 1] ) );
				}
				else moo.pb( -1 );
			}
		}
		sort( all( moo ) );
		moo.resize( unique( all( moo ) ) - moo.begin( ) );
		printf( "Case #%d: ", tt );
		if( moo.size( ) != 1 || moo[0] == -1 ) printf( "UNKNOWN" );
		else printf( "%d", moo[0] );
		printf( "\n" );
	}

	return 0;
}
