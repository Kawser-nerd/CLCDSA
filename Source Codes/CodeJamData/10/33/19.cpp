#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 520;

int R, S;
int mat[MAX][MAX];

int ploca[MAX][MAX];
int curr[MAX];
int uzmi[MAX];

struct fenwick {
  int F[MAX][MAX];

  void clear() {
    for( int i = 0; i < MAX; ++i )
      for( int j = 0; j < MAX; ++j )
        F[i][j] = 0;
  }

  void update( int a, int b ) {
    for( int x = a+1; x < MAX; x += x&-x )
      for( int y = b+1; y < MAX; y += y&-y )
        ++F[x][y];
  }

  int query( int a, int b ) {
    int ret = 0;
    for( int x = a+1; x > 0; x -= x&-x )
      for( int y = b+1; y > 0; y -= y&-y )
        ret += F[x][y];
    return ret;
  }
} F;

int query( int a, int b, int s ) {
  --a, --b;
  return F.query( a+s, b+s ) - F.query( a, b+s ) - F.query( a+s, b ) + F.query( a, b );
}

void oznaci( int a, int b, int s ) {
  for( int i = 0; i < s; ++i )
    for( int j = 0; j < s; ++j )
      F.update( a+i, b+j );
}

int main( void ) {
  int tc; scanf( "%d", &tc );
  for( int t = 1; t <= tc; ++t ) {
    fprintf( stderr, "running %d...\n", t );
    printf( "Case #%d:", t );

    scanf( "%d %d", &R, &S );
    F.clear();

    for( int i = 0; i < R; ++i ) {
      char s[500]; scanf( "%s", s );
      for( int j = 0, p = 0; j < S/4; ++j ) {
        int x = s[j]-'0';
        if( s[j] >= 'A' && s[j] <= 'Z' ) x = 10+s[j]-'A';
        mat[i][p++] = (x>>3)&1;
        mat[i][p++] = (x>>2)&1;
        mat[i][p++] = (x>>1)&1;
        mat[i][p++] = (x>>0)&1;
      }
    }

    for( int j = 0; j < S; ++j )
      for( int i = R-1, k = 1; i >= 0; --i, ++k ) {
        if( i+1 < R && mat[i][j] == mat[i+1][j] ) k = 1;
        ploca[i][j] = k;
      }

    int cnt = 0;
    for( int s = min( R, S ); s >= 1; --s ) {
      uzmi[s] = 0;
      if( s == 1 ) uzmi[s] = R*S - F.query( R, S );
      else {
        for( int i = 0; i < R; ++i ) {
          for( int j = S-1, k = 1; j >= 0; --j, ++k ) {
            if( j+1 < S && mat[i][j] == mat[i][j+1] ) k = 1;
            if( ploca[i][j] < s ) k = 0;
            curr[j] = k;
          }

          for( int j = 0; j < S; ++j ) {
            if( curr[j] >= s && query( i, j, s ) == 0 ) {
              ++uzmi[s];
              oznaci( i, j, s );
              j += s-1;
            }
          }
        }
      }
      if( uzmi[s] > 0 ) ++cnt;
    }

    printf( " %d\n", cnt );
    for( int i = min( R, S ); i >= 1; --i )
      if( uzmi[i] > 0 ) printf( "%d %d\n", i, uzmi[i] );
  }
  return 0;
}

