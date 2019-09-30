#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long llint;

int a[1000005];

int main( void ) {
  int t;
  scanf( "%d", &t );
  for( int c = 1; c <= t; ++c ) {
    int L, n, k;
    llint t;
    scanf( "%d %lld %d %d", &L, &t, &n, &k );
    for( int i = 0; i < k; ++i ) {
      int x;
      scanf( "%d", &x );
      for( int j = i; j < n; j += k )
	a[j] = x;
    }
    
    printf( "Case #%d: ", c );
    
    llint s = 0;
    int x = 0;
    while( x < n && s+2*a[x] <= t ) s += 2*a[x], x++;
    if( x == n ) { printf( "%lld\n", s ); continue; }

    sort( a + x + 1, a + n );
    reverse( a + x + 1, a + n );

    int f = min( L-1, n-x-1 ), g = min( L, n-x-1 );
    llint s1 = s, s2 = s;
    for( int i = x+1; i < n; ++i )
      s1 += 2*a[i], s2 += 2*a[i];
    for( int i = 1; i <= f; ++i ) s1 -= a[x+i];
    for( int i = 1; i <= g; ++i ) s2 -= a[x+i];
    
    llint v = (t-s)/2;
    s1 += 2*v + (a[x]-v);
    s2 += 2*a[x];
    if( L == 0 ) s1 = s2;

    printf( "%lld\n", min(s1,s2) );
  }
  return 0;
}

