#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
#include <glpk.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORI(i,v) FOR(i,(int)v.size())
#define BEND(v) v.begin(),v.end()
#define dump(x) cerr << #x << " = " << (x) << endl;
//#define dump(...)
typedef long long ll; typedef long double ld;

int cas=0;
int R,C;
char grid[16][16];
int dp[4][4][1<<16];
int dodp(int kr, int kc, int mask) {
  int& ans = dp[kr][kc][mask];
  if (ans != -1) return ans;
  ans = 0;

  for (int dr = -1; dr <= 1; dr++)
  for (int dc = -1; dc <= 1; dc++) if (dr || dc) {
    int r2 = kr+dr, c2 = kc+dc;
    if (r2 < 0 || R <= r2 || c2 < 0 || C <= c2) continue;
    if (!(mask & (1<<(r2*C+c2)))) continue;
    if (!dodp(r2,c2,mask&~(1<<(kr*C+kc)))) ans = 1;
  }

  return ans;
}
void doit() {
  scanf("%d%d",&R,&C);
  assert(R <= 4 && C <= 4);
  int mask = (1<<(R*C))-1;
  int kr=-1,kc=-1;
  FOR(r,R) FOR(c,C) {
    scanf(" %c",&grid[r][c]);
    if (grid[r][c] == '#') mask &= ~(1<<(r*C+c));
    if (grid[r][c] == 'K') {
      assert(kr == -1);
      kr = r;
      kc = c;
    }
  }
  assert(kr != -1);
  memset(dp,-1,sizeof(dp));
  bool ans = dodp(kr,kc,mask);
  printf("Case #%d: %c\n",++cas,ans?'A':'B');
}
int T;
int main() {
scanf("%d",&T);
FOR(i,T)doit();
}
