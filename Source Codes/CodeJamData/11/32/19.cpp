#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T, L, n, c, poj[ 10005 ], a[ 1000005 ];
long long t;

vector< int > Csort( vector< int > V ) {
	int len = ( int )V.size();
	
	memset( poj, 0, sizeof( poj ) );
	for( int i = 0; i < len; ++i )
		poj[ V[ i ] ]++;
	
	V.clear();
	for( int i = 10000; i >= 0; --i )
		for( int j = 0; j < poj[ i ]; ++j )
			V.push_back( i );
	
	return( V );
}

int main( void ) {
	scanf( "%d", &T );
	for( int i = 0; i < T; ++i ) {
		scanf( "%d %lld %d %d", &L, &t, &n, &c );
		for( int j = 0; j < c; ++j )
			scanf( "%d", &a[ j ] );
		
		for( int j = c; j < n; ++j )
			a[ j ] = a[ j - c ];
		
		long long suma = 0;
		for( int j = 0; j < n; ++j )
			suma += 2 * a[ j ];
		
		int poz = 0;
		while( poz < n && t >= 2 * a[ poz ] )
			t -= 2 * a[ poz++ ];
		
		vector< int > V;
		
		if( poz < n ) V.push_back( a[ poz ] - t / 2 );
		for( int j = poz + 1; j < n; ++j )
			V.push_back( a[ j ] );
		
		V = Csort( V );
		
		int len = ( int )V.size();
		for( int j = 0; L > 0 && j < len; ++j, --L )
			suma -= V[ j ];
		
		printf( "Case #%d: %lld\n", i+1, suma );
	}
	
	return( 0 );
}
