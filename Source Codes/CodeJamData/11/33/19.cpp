#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
vector< pair< long long, int > > V;

int t, n;
long long L, H, freq[ 10005 ];
long long G[ 10005 ], R;

long long GCD( long long a, long long b ) {
	while( b > 0 ) {
		long long o = a % b;
		a = b; b = o;
	}
	return( a );
}

void rek( int poz, long long x, long long a ) {
	if( x * a >= L && x * a < R ) R = x * a;
	if( poz >= ( int )V.size() ) return;
	
	long long umn = 1;
	for( int i = 0; i <= V[ poz ].second; ++i ) {
		rek( poz + 1, x * umn, a );
		umn *= V[ poz ].first;
	}
}

long long solve( long long a, long long b ) {
	long long x = b / a, org = x, d = 2;
	V.clear();
	
	while( d * d <= org ) {
		if( x % d == 0 ) {
			pair< long long, int > P( d, 0 );
			while( x % d == 0 ) { P.second++; x /= d; }
			V.push_back( P );
		}
		++d;
	}
	
	if( x > 1 ) V.push_back( make_pair( x, 1 ) );
	
	R = H+1; rek( 0, 1, a );
	return( R );
}

int main( void ) {
	scanf( "%d", &t );
	for( int i = 0; i < t; ++i ) {
		scanf( "%d %lld %lld", &n, &L, &H );
		for( int j = 0; j < n; ++j )
			scanf( "%lld", &freq[ j ] );
		
		sort( freq, freq + n );
		G[ n-1 ] = freq[ n-1 ];
		
		for( int j = n-2; j >= 0; --j )
			G[ j ] = GCD( G[ j+1 ], freq[ j ] );
		
		long long mult = 1, rez = -1;
		for( int j = 0; j < n; ++j ) {
			long long g = GCD( mult, freq[ j ] );
			
			if( H / freq[ j ] < ( mult / g ) ) break;
			if( H < ( mult / g ) * freq[ j ] ) break;
			mult = ( mult / g ) * freq[ j ];
			
			if( j == n-1 ) {
				long long x = ( ( L-1 ) / mult + 1 ) * mult;
				if( x <= H && ( rez == -1 || x < rez ) ) rez = x;
				break;
			}
			
			if( G[ j+1 ] % mult != 0 ) continue;
			
			long long x = solve( mult, G[ j+1 ] );
			if( x <= H && ( rez == -1 || x < rez ) ) rez = x;
		}
		
		long long x = solve( 1, G[ 0 ] );
		if( x <= H && ( rez == -1 || x < rez ) ) rez = x;
		
		printf( "Case #%d: ", i+1 );
		if( rez == -1 ) printf( "NO\n" );
		else printf( "%lld\n", rez );
	}
	
	return( 0 );
}
