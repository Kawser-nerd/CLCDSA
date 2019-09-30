#include <stdio.h>
#include <string>


int main() {
  long t;
  scanf( "%ld", &t );

  for( int i = 1; i <= t; i++ ) {
    long r;
    long c;

    scanf( "%ld %ld", &r, &c );

    std::string tile;

    char line[ 128 ];
    for( int j = 0; j < r; j++ ) {
      scanf( "%s", line );
      tile.append( line );
    }

    bool impossible = false;
    for( int j = 0; j < r && !impossible; j++ ) {
      for( int k = 0; k < c && !impossible; k++ ) {
	int idx0 = j * c + k;
	int idx1 = j * c + k + 1;
	int idx2 = ( j + 1 ) * c + k;
	int idx3 = ( j + 1 ) * c + k + 1;

	if( tile[ idx0 ] == '#' ) {
	  if( idx3 >= (int)tile.length() || j >= c ) {
	    impossible = true;
	  }
	  else if( tile[ idx1 ] == '#' && tile[ idx2 ] == '#' && tile[ idx3 ] == '#' ) {
	    tile[ idx0 ] = '/';
	    tile[ idx1 ] = '\\';
	    tile[ idx2 ] = '\\';
	    tile[ idx3 ] = '/';
	  }
	  else {
	    impossible = true;
	  }
	}
      }
    }

    printf( "Case #%d:\n", i );
    if( impossible ) {
      printf( "Impossible\n" );
    }
    else {
      for( int j = 0; j < r; j++ ) {
	std::string subStr = tile.substr( j * c, c );
	printf( "%s\n", subStr.c_str() );
      }
    }
  }

  return 0;
}
