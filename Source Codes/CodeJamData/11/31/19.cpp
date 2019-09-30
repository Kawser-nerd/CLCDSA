#include <cstdio>
#include <cstdlib>

int t, r, c;
char mat[ 55 ][ 55 ];

int main( void ) {
	scanf( "%d", &t );
	for( int i = 0; i < t; ++i ) {
		scanf( "%d %d", &r, &c );
		for( int j = 0; j < r; ++j )
			scanf( "%s", mat[ j ] );
		
		int possible = 1;
		for( int j = 0; j < r; ++j )
			for( int k = 0; k < c; ++k ) {
				if( !possible ) break;
				if( mat[ j ][ k ] != '#' ) continue;
				
				if( j == r-1 || k == c-1 ) { possible = 0; break; }
				
				if( mat[ j+1 ][ k ] != '#' ) { possible = 0; break; }
				if( mat[ j ][ k+1 ] != '#' ) { possible = 0; break; }
				if( mat[ j+1 ][ k+1 ] != '#' ) { possible = 0; break; }
				
				mat[ j ][ k ] = mat[ j+1 ][ k+1 ] = '/';
				mat[ j+1 ][ k ] = mat[ j ][ k+1 ] = '\\';
			}
		
		printf( "Case #%d:\n", i+1 );
		if( !possible ) { printf( "Impossible\n" ); continue; }
		
		for( int j = 0; j < r; ++j )
			printf( "%s\n", mat[ j ] );
	}
	
	return( 0 );
}
