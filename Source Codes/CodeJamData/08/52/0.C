#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct state
{
  int r, c, tm;
  state(int r, int c, int tm) : r(r), c(c), tm(tm) {}
};

struct comp
{
  bool operator()(const state &s1, const state &s2) const
  {
    return s1.tm > s2.tm;
  }
};

int R, C;
int sR, sC;
char map[17][17];
bool vis[16][16];
const int dr[] = {  0, -1, 0, 1 };
const int dc[] = { -1,  0, 1, 0 };

int fastest()
{
  priority_queue<state, vector<state>, comp> Q;
  Q.push(state(sR, sC, 0));
  memset(vis, 0, sizeof(vis));
  while ( !Q.empty() )
  {
    state S = Q.top(); Q.pop();
    if ( map[S.r][S.c] == 'X' )
      return S.tm;
    if ( vis[S.r][S.c] )
      continue;
    vis[S.r][S.c] = true;
    for ( int d=0; d<4; ++d )
    {
      int nr = S.r + dr[d];
      int nc = S.c + dc[d];
      if ( nr>=0 and nr<R and nc>=0 and nc<C and map[nr][nc] != '#' 
          and not vis[nr][nc] )
        Q.push(state(nr, nc, S.tm + 1));
    }
    // shoot
    for ( int yel=0; yel<4; ++yel )
    {
      int sr = S.r, sc = S.c;
      int yelt = 0;
      while ( sr>=0 and sr<R and sc>=0 and sc<C and map[sr][sc] != '#' )
      {
        sr += dr[yel];
        sc += dc[yel];
        ++yelt;
      }
      for ( int bl=0; bl<4; ++bl )
        if ( yel != bl )
        {
          int psr = S.r, psc = S.c;
          sr = psr + dr[bl]; sc = psc + dc[bl];
          while ( sr>=0 and sr<R and sc>=0 and sc<C and map[sr][sc] != '#' )
          {
            psr = sr; psc = sc;
            sr += dr[bl];
            sc += dc[bl];
          }
          if ( not vis[psr][psc] )
            Q.push(state(psr, psc, S.tm + yelt));
        }
    }
  }

  return -1;
}


int process_case()
{
  cin >> R >> C;
  for ( int r=0; r<R; ++r )
  {
    string cr;
    cin >> cr;
    for ( int c=0; c<C; ++c )
    {
      map[r][c] = cr[c];
      if ( cr[c] == 'O' )
      {
        sR = r; sC = c;
      }
    }
  }
  return fastest();
}


int main()
{
  int N;
  cin >> N;
  for ( int nc=1; nc<=N; ++nc )
  {
    int res = process_case();
    if ( res >= 0 )
      cout << "Case #" << nc << ": " << res << endl;
    else
      cout << "Case #" << nc << ": THE CAKE IS A LIE" << endl;
  }
  return 0;
}
          


