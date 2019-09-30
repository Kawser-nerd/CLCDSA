#include <cstdio>
#include <vector>
#include <limits>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

constexpr int MAX_N = 100000, MAX_M = 200000, INF = std::numeric_limits<int>::max()>>2;

struct edge
{ int to, dist; };

int N, M;
int L[MAX_M], R[MAX_M], D[MAX_M];
std::vector<edge> G[MAX_N];
int d[MAX_N];
bool used[MAX_N];
bool fl = true;

void dfs( int v, int prv )
{
  if( used[v] )
    return;

  used[v] = true;

  for( auto &e : G[v] ) if( !used[e.to] )
  {
    d[e.to] = d[v]+e.dist;

    dfs( e.to, v );
  }

  return;
}

int main()
{
  scanf( "%d%d", &N, &M );
  rep( i, M )
  {
    scanf( "%d%d%d", L+i, R+i, D+i );
    --L[i]; --R[i];
    G[L[i]].push_back( (edge){ R[i], D[i] } );
    G[R[i]].push_back( (edge){ L[i], -D[i] } );
  }

  std::fill( d, d+N, INF );

  rep( i, N ) if( d[i] == INF )
  {
    d[i] = 0;
    dfs( i, -1 );
  }

  rep( i, M )
    fl &= d[R[i]]-d[L[i]] == D[i];

  puts( fl ? "Yes" : "No" );
  
  return 0;
}