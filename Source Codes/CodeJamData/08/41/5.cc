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
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////



int main() {
  int T;
  cin >> T;
  FOR(t,1,T) {
    int M, V;
    cin >> M >> V;
    vector<int> type(M+1), canChange(M+1), value(M+1,-1), changesTo0(M+1), changesTo1(M+1);
    int I = (M-1)/2;
    FOR(i,1,I) cin >> type[i] >> canChange[i];
    FOR(i,I+1,M) {
      cin >> value[i];
      changesTo0[i] = changesTo1[i] = 987654321;
      if (value[i]) changesTo1[i]=0; else changesTo0[i]=0;
    }
    FORD(i,I,1) {
      changesTo0[i] = changesTo1[i] = 987654321;
      if (type[i]==0) {
        // or gate
        value[i] = value[2*i] | value[2*i+1];
        if (value[i]) {
          changesTo1[i]=0;
          if (canChange[i]) changesTo0[i]=min( changesTo0[i], 1+min(changesTo0[2*i],changesTo0[2*i+1]) );
          changesTo0[i]=min( changesTo0[i], changesTo0[2*i]+changesTo0[2*i+1] );
        } else {
          changesTo0[i]=0;
          changesTo1[i]=min( changesTo1[2*i], changesTo1[2*i+1] );
        }
      } else {
        // and gate
        value[i] = value[2*i] & value[2*i+1]; 
        if (value[i]) {
          changesTo1[i]=0;
          changesTo0[i]=min( changesTo0[2*i], changesTo0[2*i+1] );
        } else {
          changesTo0[i]=0;
          if (canChange[i]) changesTo1[i]=min( changesTo1[i], 1+min(changesTo1[2*i],changesTo1[2*i+1]) );
          changesTo1[i]=min( changesTo1[i], changesTo1[2*i]+changesTo1[2*i+1] );
        }
      }
    }
    int res=-1;
    if (V) {
      if (changesTo1[1] < 987654321) res = changesTo1[1];
    } else {
      if (changesTo0[1] < 987654321) res = changesTo0[1];
    }
    if (res==-1)
      printf("Case #%d: IMPOSSIBLE\n",t);
    else
      printf("Case #%d: %d\n",t,res);
  }

  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
