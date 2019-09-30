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
int R,C,mid;
int grid[5][5];
int neigh[5][5];
bool out[5][5];
int now;
int ans;
void doit2(int r, int c) {
  if (r >= R) {
    doit2(0,c+1);
    return;
  }
  if (c >= C) {
    FOR(r2,R) FOR(c2,C) assert(grid[r2][c2] == 0);
    setmax(ans, now);
    return;
  }

  bool happy = 1;
  for (int r2 = max(r-1,0); r2 <= min(r+1,R-1); r2++) {
    for (int c2 = max(c-1,0); c2 <= min(c+1,C-1); c2++) {
      if (--neigh[r2][c2] == 0 && grid[r2][c2] != 0) happy = 0;
    }
  }

  if (happy) doit2(r+1, c);

  for (int r2 = max(r-1,0); r2 <= min(r+1,R-1); r2++) {
    for (int c2 = max(c-1,0); c2 <= min(c+1,C-1); c2++) {
      ++neigh[r2][c2];
    }
  }

  happy = 1;
  for (int r2 = max(r-1,0); r2 <= min(r+1,R-1); r2++) {
    for (int c2 = max(c-1,0); c2 <= min(c+1,C-1); c2++) {
      if (--grid[r2][c2] < 0) happy = 0;
      if (--neigh[r2][c2] == 0 && grid[r2][c2] != 0) happy = 0;
    }
  }

  if (r == mid) now++;
  if (happy) doit2(r+1,c);
  if (r == mid) now--;

  for (int r2 = max(r-1,0); r2 <= min(r+1,R-1); r2++) {
    for (int c2 = max(c-1,0); c2 <= min(c+1,C-1); c2++) {
      ++grid[r2][c2];
      ++neigh[r2][c2];
    }
  }
}
void doit() {
  scanf("%d%d",&R,&C);

  FOR(r,R) FOR(c,C) scanf("%d",&grid[r][c]);

  FOR(r,R) FOR(c,C) {
    neigh[r][c] =
        (r==0 || r==R-1) && (c==0 || c==C-1) ? 4
      : (r==0 || r==R-1) || (c==0 || c==C-1) ? 6
      :                                        9;
  }

  mid = R/2;
  ans = 0;
  now = 0;
  doit2(0,0);

  printf("Case #%d: %d\n", ++cas, ans);
}

int TESTS;
int main() {
  scanf("%d",&TESTS);
  FOR(i,TESTS) doit();
}
