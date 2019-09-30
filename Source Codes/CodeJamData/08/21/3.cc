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
#define REP(i,n) for(int i=0;i<(int)(n);++i)
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

long long cnt[4][4];

int main() {
  int T;
  cin >> T;
  FOR(t,1,T) {
    long long A,B,C,D,x0,y0,M,n;
    cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
    memset(cnt,0,sizeof(cnt));
    long long X=x0, Y=y0;
    cnt[X%3][Y%3]++;
    for (int i=0; i<n-1; i++) {
      X = (A*X+B)%M;
      Y = (C*Y+D)%M;
      cnt[X%3][Y%3]++;
    }
    long long res3=0, res2=0, res1=0;
    REP(x1,3) REP(y1,3) REP(x2,3) REP(y2,3) REP(x3,3) REP(y3,3) {
      if (x1==x2 && y1==y2) continue;
      if (x1==x3 && y1==y3) continue;
      if (x2==x3 && y2==y3) continue;
      if ((x1+x2+x3)%3) continue;
      if ((y1+y2+y3)%3) continue;
      res3 += cnt[x1][y1] * cnt[x2][y2] * cnt[x3][y3];
    }
    res3 /= 6;
    REP(x1,3) REP(y1,3) REP(x2,3) REP(y2,3) {
      if (x1==x2 && y1==y2) continue;
      if ((x1+x1+x2)%3) continue;
      if ((y1+y1+y2)%3) continue;
      res2 += cnt[x1][y1] * (cnt[x1][y1]-1) * cnt[x2][y2];
    }
    res2 /= 2;
    REP(x1,3) REP(y1,3) {
      cerr << "cnt " << x1 << " " << y1 << " = " << cnt[x1][y1] << endl;
      if ((x1+x1+x1)%3) continue;
      if ((y1+y1+y1)%3) continue;
      res1 += cnt[x1][y1] * (cnt[x1][y1]-1) * (cnt[x1][y1]-2);
    }
    res1 /= 6;
    cerr << res3 << " " << res2 << " " << res1 << endl;
    long long res = res3 + res2 + res1;
    cout << "Case #" << t << ": " << res << endl;
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
