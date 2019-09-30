#include <cstdio>
#include <algorithm>

using namespace std;

char a[55][55];
int main( void ) {
  int t;
  scanf( "%d", &t );
  for( int c = 1; c <= t; ++c ) {
    int n, m;
    scanf( "%d %d", &n, &m );
    for( int i = 0; i < n; ++i )
      scanf( "%s", a[i] );

    int ok = 1;
    for( int i = 0; i < n; ++i )
      for( int j = 0; j < m; ++j )
	if( a[i][j] == '#' ) {
	  if( i+1 == n || a[i+1][j] != '#' ) ok = 0;
	  if( j+1 == m || a[i][j+1] != '#' ) ok = 0;
	  if( a[i+1][j+1] != '#' ) ok = 0;
	  a[i][j] = a[i+1][j+1] = '/', a[i][j+1] = a[i+1][j] = 92;
	}

    printf( "Case #%d:\n", c );
    if( !ok ) puts( "Impossible" ); else
      for( int i = 0; i < n; ++i )
	puts( a[i] );
  }
  return 0;
}

