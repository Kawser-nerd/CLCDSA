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
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
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

int TTT;
int N;
int X[512],Y[512],R[512],S[512];

#define DOCIAHNE(i,j) ( (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]) <= R[i]*R[i] )

int main() {
  cin >> TTT;
  FOR(ttt,1,TTT) {
    cin >> N;
    REP(n,N) cin >> X[n] >> Y[n] >> R[n] >> S[n];
    int best = 0;
    REP(nove,1<<N) {
      int ok = 1;
      REP(i,N) if (nove & 1<<i) REP(j,N) if (!(nove & 1<<j)) if (DOCIAHNE(i,j)) ok = 0;
      if (ok) {
        int toto = 0;
        REP(i,N) if (nove & 1<<i) toto += S[i];
        best = max(best,toto);
      }
    }
    cout << "Case #" << ttt << ": " << best << endl;
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
