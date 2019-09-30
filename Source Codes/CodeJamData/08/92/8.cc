
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
bool mark[100][100];
int W,H,X[2],Y[2],X0,Y0;
void dfs(int x, int y) {
  if (x < 0 || x >= W || y < 0 || y >= H) return;
  if (mark[x][y]) return;
  mark[x][y] = 1;

  FOR(i,2) dfs(x+X[i], y+Y[i]);
}
void doit() {
  scanf("%d%d",&W,&H);
  FOR(i,2) scanf("%d%d",&X[i],&Y[i]);
  scanf("%d%d",&X0,&Y0);

  memset(mark,0,sizeof(mark));
  dfs(X0,Y0);
  int ans = 0;
  FOR(x,W) FOR(y,H) ans += mark[x][y];

  printf("Case #%d: %d\n", ++cas, ans);
}

int TESTS;
int main() {
  scanf("%d",&TESTS);
  FOR(i,TESTS) doit();
}
