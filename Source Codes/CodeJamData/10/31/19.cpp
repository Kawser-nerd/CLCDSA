#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[1010];
int b[1010];

int main( void ) {
  int tc; scanf( "%d", &tc );
  for( int t = 1; t <= tc; ++t ) {
    scanf( "%d", &n );
    for( int i = 0; i < n; ++i )
      scanf( "%d %d", &a[i], &b[i] );

    int ans = 0;
    for( int i = 0; i < n; ++i )
      for( int j = i+1; j < n; ++j ) {
        if( a[i] < a[j] && b[i] > b[j] ) ++ans;
        if( a[j] < a[i] && b[j] > b[i] ) ++ans;
      }
    printf( "Case #%d: %d\n", t, ans );
  }
  return 0;
}

