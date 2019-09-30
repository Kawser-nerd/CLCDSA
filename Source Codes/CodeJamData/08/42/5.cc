// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

long long N,M,A;

bool good(long long X, int &x, int &y) {
  if (X==0) { x=y=0; return true; }
  for (int i=1; i<=M; i++)
    if ((X%i)==0)
      if ((X/i) <= N) {
        x=X/i; y=i; return true;
      }
  return false;
}

int main() {
  int T;
  cin >> T;
  FOR(t,1,T) {
    cin >> N >> M >> A;
    long long plus = A, minus = 0;
    int x2,y2,x3,y3;
    bool mam = false;
    while (1) {
      if (plus > M*N) break;
      if (good(plus,x2,y3))
        if (good(minus,x3,y2)) {
          mam=true;
          break;
        }
      plus++; minus++;
    }
    if (mam)
      printf("Case #%d: %d %d %d %d %d %d\n",t,0,0,x2,y2,x3,y3);
    else
      printf("Case #%d: IMPOSSIBLE\n",t);
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
