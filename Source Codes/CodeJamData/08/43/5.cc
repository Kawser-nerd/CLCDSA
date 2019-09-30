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

int N;
double X[1020], Y[1020], Z[1020], P[1020];

inline double eval(double x, double y, double z) {
  double res = 0.0;
  REP(i,N) res = max( res, (abs(x-X[i]) + abs(y-Y[i]) + abs(z-Z[i]))/P[i] );
  return res;
}

int main() {
  int T;
  cin >> T;
  FOR(t,1,T) {
    cin >> N;
    REP(i,N) cin >> X[i] >> Y[i] >> Z[i] >> P[i];
    double x=accumulate(X+0,X+N,0.)/N;
    double y=accumulate(Y+0,Y+N,0.)/N;
    double z=accumulate(Z+0,Z+N,0.)/N;
    double step=1;
    while (1) {
      double curr = eval(x,y,z);
      double best = curr+1, bestx, besty, bestz;
      for (int dx=-1; dx<=1; dx++)
      for (int dy=-1; dy<=1; dy++)
      for (int dz=-1; dz<=1; dz++) {
        double nx=x+dx*step, ny=y+dy*step, nz=z+dz*step;
        double toto = eval(nx,ny,nz);
        if (toto < best) { best=toto; bestx=nx; besty=ny; bestz=nz; }
      }
      if (best < curr - 1e-8) {
        x=bestx; y=besty; z=bestz;
      } else {
        step *= 0.5;
        if (step < 1e-8) break;
      }
    }
    printf("Case #%d: %.9f\n",t,eval(x,y,z));
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
