#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <limits>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

constexpr int INF = std::numeric_limits<int>::max()>>2;

int A, B;
int d[10][10];
int c[100][100];

int main()
{
  scanf( "%d%d", &A, &B );
  rep( i, A ) rep( j, B )
    scanf( "%d", &d[i][j] );

  rep( i, 101 ) rep( j, 101 )
  {
    rep( a, A ) rep( b, B )
      c[i][j] = std::max( c[i][j], d[a][b]-i*(a+1)-j*(b+1) );
  }

  bool fl = true;
  rep( a, A ) rep( b, B )
  {
    int D = INF;
    rep( i, 101 ) rep( j, 101 )
      D = std::min( D, i*(a+1)+j*(b+1)+c[i][j] );
    
    fl &= D == d[a][b];
  }

  if( !fl )
    puts( "Impossible" );
  else
  {
    puts( "Possible" );
  
    printf( "%d %d\n", 202, 101*101+200 );

    rep( i, 100 )
      printf( "%d %d X\n", i+1, i+2 );
    rep( i, 100 )
      printf( "%d %d Y\n", i+102, i+103 );  
    rep( i, 101 ) rep( j, 101 )
      printf( "%d %d %d\n", i+1, 202-j, c[i][j] );
    printf( "%d %d\n", 1, 202 );
  }

  return 0;
}