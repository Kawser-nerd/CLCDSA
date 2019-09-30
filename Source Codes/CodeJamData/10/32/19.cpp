#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long llint;

int main( void ) {
  int tc; scanf( "%d", &tc );
  for( int t = 1; t <= tc; ++t ) {
    llint a, b, c;
    scanf( "%lld %lld %lld", &a, &b, &c );
    llint w = 0;
    while( a < b ) a *= c, ++w;
    llint ans = 0, p = 1;
    while( p < w ) p *= 2, ++ans;
    printf( "Case #%d: %lld\n", t, ans );
  }
  return 0;
}

