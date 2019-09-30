#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

int main() {
  long t;
  scanf( "%ld", &t );

  for( int i = 1; i <= t; i++ ) {
    long l;
    long lt;
    long n;
    long c;

    std::map< long, long > cntMap;
    long long total = 0;

    scanf( "%ld %ld %ld %ld", &l, &lt, &n, &c );
    long* ds = new long[ c ];
    for( int j = 0; j < c; j++ ) {
      long d;
      scanf( "%ld", &d );

      total += 2 * d;
      ds[ j ] = d;
    }


    int m = lt / total;
    total *= m;
    long r0 = n / c;
    long r1 = n % c;

    for( int j = 0; j < c; j++ ) {
      long d = ds[ j ];
      long r = lt - total;
      long flg = ( j < r1 ? 1 : 0 );

      if( cntMap.find( d ) == cntMap.end() ) {
	cntMap[ d ] = 0;
      }

      if( r <= 0 ) {
	cntMap[ d ] += ( r0 - m + flg );
      }
      else if( r >= 2 * d ) {
	total += d * 2;
	cntMap[ d ] += ( r0 - m - 1 + flg );
      }
      else {
	long d0 = r / 2;
	long d1 = d - d0;

	if( cntMap.find( d1 ) == cntMap.end() ) {
	  cntMap[ d1 ] = 0;
	}
	cntMap[ d1 ] += 1;
	cntMap[ d ] += ( r0 - m - 1 + flg );

	total += d0 * 2;
      }
    }

    std::vector< long > keys;
    for( std::map< long, long >::iterator it = cntMap.begin(); it != cntMap.end(); it++ ) {
      keys.push_back( (*it).first );
    }
    std::sort( keys.begin(), keys.end() );

    long useL = 0;
    for( int j = (int)keys.size() - 1; j >= 0; j-- ) {
      long d = keys[ j ];
      long cnt = cntMap[ d ];

      if( useL >= l ) {
	total += cnt * ( d * 2 );
      }
      else {
	long maxL = l - useL;
	if( maxL >= cnt ) {
	  total += cnt * d;
	  useL += cnt;	
	}
	else {
	  total += maxL * d + 2 * d * ( cnt - maxL );
	  useL += maxL;
	}
      }
    }

    delete[] ds;
    printf( "Case #%d: %lld\n", i, total );
  }

  return 0;
}
