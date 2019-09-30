#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long llint;

const int N = 20000003;
const int MOD = 1000000007;

llint a[N];
llint s[N];
llint sums[N];
int cnt = 0, inv;

llint pow( int a, int b ) {
  if( b == 0 ) return 1;
  if( b&1 ) return ( llint( a )*pow( a, b-1 ) )%MOD;
  llint tmp = pow( a, b/2 );
  return ( tmp*tmp )%MOD;
}

int main( void ) {
  for( int i = 0; i < 10000001; ++i ) {
    llint v = i;
    int x = i, c = 0;
    while( x > 0 ) {
      v = v*10+( x%10 );
      x /= 10, c++;
    }

    a[cnt++] = v;
    v = i, x = i/10;
    while( x > 0 ) {
      v = v*10+( x%10 );
      x /= 10;
    }
    a[cnt++] = v;
  }
  sort( a, a + cnt );
 
  int inv = pow( 2, MOD-2 );

  int t;
  scanf( "%d", &t );
  for( int d = 1; d <= t; ++d ) {
    llint l, r;
    scanf( "%lld %lld", &l, &r );

    llint sol = 0;
    int p1 = ( lower_bound( a, a+cnt, l )-a ), p2 = ( upper_bound( a, a+cnt, r )-a );
    llint last = l;
    for( int i = p1; i < p2; ++i ) {
      s[i] = a[i]-last+1;
      s[i] %= MOD;
      last = a[i]+1;

      llint v = ( s[i]*( s[i]-1+MOD ) )%MOD;
      v = ( v*inv )%MOD;
      sol = ( sol + v )%MOD;
    }
    s[p2] = r-last+2;
    llint v = ( s[p2]*( s[p2]-1+MOD ) )%MOD;
    v = ( v*inv )%MOD;
    sol = ( sol + v )%MOD;

    sums[p2] = s[p2], sums[p2-1] = s[p2-1];
    for( int i = p2-2; i >= p1; --i )
      sums[i] = ( sums[i+2] + s[i] )%MOD;

    for( int i = p1; i < p2-1; ++i )
      sol = ( sol + s[i]*sums[i+2] )%MOD;
    printf( "Case #%d: %lld\n", d, sol );
  }
  return 0;
}
