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

set< vector< int > > used;
set< pair< double, vector< int > > > moo;
double a[10005][4];

int main( )
{
	int i, j, k, t, tt;

	freopen( "in.txt", "r", stdin );
	freopen( "out.txt", "w", stdout );

	scanf( "%d", &t );
	for( tt = 1; tt <= t; ++ tt )
	{
		fprintf( stderr, "%d\n", tt );
		scanf( "%d %d", &m, &n );
		used.clear( );
		moo.clear( );
		double zz = 1;
		fi( n )
		{
			fj( 4 ) scanf( "%lf", &a[i][j] );
			sort( a[i], a[i] + 4, greater< double > () );
			zz *= a[i][0];
		}

		double ans = 0;
		vector< int > vec;
		fi( n ) vec.pb( 0 );
		moo.insert( mp( zz, vec ) );
		fi( m )
		{
			vector< int > cur;
			double prob;
			while( moo.size( ) && cur.empty( ) )
			{
				set< pair< double, vector< int > > > :: iterator it = moo.end( );
				-- it;
				if( used.find( it->second ) == used.end( ) )
				{
					cur = it->second;
					prob = it->first;
				}
				moo.erase( it );
			}
			if( cur.empty( ) )
			{
				ans = 1;
				break;
			}
			used.insert( cur );
			ans += prob;
			fj( n ) if( cur[j] < 3 && a[j][cur[j]] > 1e-9 )
			{
				double la = prob / a[j][cur[j]];
				++ cur[j];
				la = la * a[j][cur[j]];
				moo.insert( mp( la, cur ) );
				-- cur[j];
			}
		}

		printf( "Case #%d: ", tt );
		printf( "%.18lf", ans );
		printf( "\n" );
	}

	return 0;
}
