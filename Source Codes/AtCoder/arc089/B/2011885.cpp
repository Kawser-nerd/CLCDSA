#include <cstdio>
#include <algorithm>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

constexpr int MAX_N = 100000, MAX_K = 1000;

int N, K;
int fld[2*MAX_K][2*MAX_K], S[4*MAX_K+1][4*MAX_K+1], S_mod[2*MAX_K+1][2*MAX_K+1];

int main()
{
  scanf( "%d%d", &N, &K );

  int ox, oy;
  rep( i, N )
  {
    int x, y;
    char c;
    scanf( "%d%d %c", &x, &y, &c );

    if( c == 'W' )
      y += K;

    x %= 2*K;
    y %= 2*K;
    //++fld[(x+add)%(2*K)][y%(2*K)];
    //++fld[x%(2*K)][(y+add)%(2*K)];
    
    ++S[x][y];
    --S[x][y+K];
    --S[x+K][y];
    ++S[x+K][y+K];

    ++S[x+K][y+K];
    --S[x+K][y+2*K];
    --S[x+2*K][y+K];
    ++S[x+2*K][y+2*K];

    /*nx = (x+add)%(2*K), ny = y%(2*K);
    left = std::max( 0, nx-K ), bottom = std::min( 2*K-1, ny+K );
    
    ++S[left][ny];
    --S[nx+1][ny];
    --S[left][bottom];
    ++S[nx+1][bottom];*/
  }

  rep( i, 4*K+1 ) rep( j, 4*K )
    S[i][j+1] += S[i][j];
  rep( i, 4*K ) rep( j, 4*K+1 )
    S[i+1][j] += S[i][j];

  rep( i, 4*K ) rep( j, 4*K )
    S_mod[i%(2*K)][j%(2*K)] += S[i][j];

  int ans = 0;
  rep( i, 2*K ) rep( j, 2*K )
    ans = std::max( ans, S_mod[i][j] );

  printf( "%d\n", ans );

  return 0;
}