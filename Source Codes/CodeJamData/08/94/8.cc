#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <ext/hash_map>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>
#include <glpk.h> // http://www.gnu.org/software/glpk/
using namespace std;
using namespace __gnu_cxx;

#define FR(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORI(i,v) FOR(i,(int)v.size())
#define RF(i,a,b) for(int i=(a)-1;i>=b;--i)
#define ROF(i,n) RF(i,n,0)
#define FORALL(i,v) for(typeof(v.end())i=v.begin();i!=v.end();++i)
#define ROFALL(i,v) for(typeof(v.rend())i=v.rbegin();i!=v.rend();++i)
#define BEND(v) v.begin(),v.end()
#define setmax(a,b) (a) = max(a,b)
#define dump(x) cerr << #x << " = " << (x) << endl;
typedef long long ll; typedef long double ld;

namespace __gnu_cxx {
  template<>
  struct hash<string> {
    size_t operator()(const string &s) const {
      size_t h = 0;
      FORALL(i,s) h = 107*h + *i;
      return h;
    }
  };
}

int cas=0;
int dr[] = { 0, 1, 0, -1 },
    dc[] = { 1, 0, -1, 0 };
int N,M;
char grid[30][30];
int dist[30][30];
deque<pair<int,int> > q;
void bfs() {
  memset(dist,-1,sizeof(dist));
  FORALL(i,q) dist[i->first][i->second] = 0;

  while (q.size()) {
    int r = q.front().first, c = q.front().second;
    q.pop_front();

    FOR(k,4) {
      int r2 = r+dr[k], c2 = c+dc[k];
      if (r2 < 0 || r2 >= N || c2 < 0 || c2 >= M) continue;
      if (grid[r2][c2] == '.') continue;
      if (dist[r2][c2] != -1) continue;
      dist[r2][c2] = 1 + dist[r][c];
      q.push_back(make_pair(r2,c2));
    }
  }
}
int calc(int n) {
  return n*(n+1)/2;
}
void doit() {
  scanf("%d%d",&N,&M);

  FOR(i,N) FOR(j,M) scanf(" %c",&grid[i][j]);

  int fr=-1,fc=-1;
  FOR(i,N) FOR(j,M) if ((i||j) && grid[i][j] == 'T') fr = i, fc = j;

  q.push_back(make_pair(0,0));
  bfs();
  
  int ans = 0;
  if (fr != -1) {
    int pathlen = dist[fr][fc];
    pathlen++;

    q.push_back(make_pair(0,0));
    q.push_back(make_pair(fr,fc));
    bfs();

    ans += calc(pathlen) - (calc(pathlen/2) + calc((pathlen+1)/2));
  }
  FOR(r,N) FOR(c,M) if (dist[r][c] != -1) ans += dist[r][c];

  printf("Case #%d: %d\n", ++cas, ans);
}

int TESTS;
int main() {
  scanf("%d",&TESTS);
  FOR(i,TESTS) doit();
}
