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

int ret[55][55];

bool winning( int a, int b )
{
	if( a == 0 || b == 0 ) return true;
	if( ret[a][b] ) return ret[a][b] == 1;
	ret[a][b] = -1;
	for( int k = 1; k < 50; ++ k )
	{
		if( a - b * k >= 0 )
		{
			if( !winning( a - b * k, b ) )
			{
				ret[a][b] = 1;
				return true;
			}
		}
		if( b - a * k >= 0 )
		{
			if( !winning( b - a * k, a ) )
			{
				ret[a][b] = 1;
				return true;
			}
		}
	}
	return false;
}

int nxt[2000005];
int downto[2000005];

int inter( int a1, int a2, int b1, int b2 )
{
	if( b1 > a2 || a1 > b2 ) return 0;
	return min( b2, a2 ) - max( b1, a1 ) + 1;
}

int main( )
{
	int i, j, k, t, tt;

	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );

	/*for( int i = 1; i < 12; ++ i )
		for( int j = 1; j < 30; ++ j )
			if( winning( i, j ) ) printf( "%d %d: w\n", i, j );
			else printf( "%d %d: l\n", i, j ); */

	downto[2] = 2;
	downto[3] = 2;
	nxt[3] = 2;
	nxt[4] = 3;
	int moo = 2;
	for( int i = 3; i <= 1000000; ++ i )
	{
		if( nxt[i] != 0 ) moo = nxt[i];
		downto[i] = moo;
		nxt[i + downto[i]] = i + 1;
	}

	scanf( "%d\n", &tt );
	for( t = 1; t <= tt; ++ t )
	{
		printf( "Case #%d:", t );
		int a1, a2, b1, b2;
		scanf( "%d %d %d %d", &a1, &a2, &b1, &b2 );
	
		long long ans = 0;
		for( int i = a1; i <= a2; ++ i )
		{
			long long cur = b2 - b1 + 1;
			if( i == 1 )
			{
				if( b1 <= 1 && b2 >= 1 ) -- cur;
			}
			else if( i == 2 )
			{
				if( b1 <= 2 && b2 >= 2 ) -- cur;
				if( b1 <= 3 && b2 >= 3 ) -- cur;
			}
			else
			{
				cur -= inter( b1, b2, downto[i], i + downto[i] - 1 );
			}
			ans += cur;
		}
		printf( " %lld\n", ans );
	}

	return 0;
}
