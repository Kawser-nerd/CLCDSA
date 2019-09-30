#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long llint;

llint a[10005];
llint lcm[10005];

llint gcd( llint a, llint b ) {
  if( b == 0 ) return a;
  return gcd( b, a%b );
}

int main( void ) {
  int t;
  scanf( "%d", &t );
  for( int c = 1; c <= t; ++c ) {
    int n;
    llint lo, hi;
    scanf( "%d %lld %lld", &n, &lo, &hi );
    for( int i = 0; i < n; ++i )
      scanf( "%lld", a+i );
    sort( a, a + n );

    llint lc = 1;
    double l = 1;
    int gg = 0;
    for( int i = 0; i < n; ++i ) {
      llint g = gcd( lc, a[i] );
      lc /= g, l /= g;
      lc *= a[i], l *= a[i];
      lcm[i] = lc;
      if( l > hi*10LL ) break; else
	if( lc > hi ) break;
      gg++;
    }

    llint ans = -1;
    if( gg == n ) {
      if( lc >= lo && lc <= hi ) ans = lc; else
	if( lc < lo ) ans = lo + lc - (lo%lc);
    }

    llint g = a[n-1];
    for( int i = n-1; i >= 0; --i ) {
      g = gcd( g, a[i] );
      llint lc = 1, le = 0;

      if( i > 0 ) { 
	if( gg < i-1 ) continue;
	lc = lcm[i-1], le = a[i-1];
      }      

      if( g%lc ) continue;
    
      llint f = g / lc;
      for( llint j = 1; j*j <= f; ++j )
	if( f%j == 0 ) {
	  llint x = j*lc;
	  if( x >= lo && x <= hi && x >= le && x <= a[i] )
	    if( ans == -1 || x < ans ) ans = x;
	  
	  x = (f/j)*lc;
	  if( x >= lo && x <= hi && x >= le && x <= a[i] )
	    if( ans == -1 || x < ans ) ans = x;
	}
    }

    printf( "Case #%d: ", c );
    if( ans == -1 ) puts( "NO" ); else
      printf( "%lld\n", ans );
  }
  return 0;
}

