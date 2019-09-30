#include <cstdio>
#include <map>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

int N, C;
int D[30][30];
int c[500][500];
int num[3];
std::map<int, int> cnt[3];

int main()
{
  scanf( "%d%d", &N, &C );
  rep( i, C ) rep( j, C )
    scanf( "%d", &D[i][j] );
  
  rep( i, N ) rep( j, N )
    scanf( "%d", &c[i][j] ), --c[i][j];

  rep( i, N ) rep( j, N )
  {
    int m = (i+j) % 3;

    ++num[m];
    ++cnt[m][c[i][j]];
  }

  int ans = 1<<30;

  rep( i, C ) rep( j, C ) rep( k, C ) if( i != j && j != k && i != k )
  {
    int sum = 0;

    for( auto it = cnt[0].begin(); it != cnt[0].end(); ++it )
      sum += D[it->first][i]*it->second;
    for( auto it = cnt[1].begin(); it != cnt[1].end(); ++it )
      sum += D[it->first][j]*it->second;
    for( auto it = cnt[2].begin(); it != cnt[2].end(); ++it )
      sum += D[it->first][k]*it->second;

    ans = std::min( ans, sum );
  }

  printf( "%d\n", ans );

  return 0;
}