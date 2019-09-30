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
#include <cstring>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int T; string Tline;

int N, K, P;
int ways[1100][1024];
int MOD = 30031;

int solve(int next, int pattern) {
  int &res = ways[next][pattern];
  if (next == N && pattern == ( (1<<K)-1 )) return res = 1;
  if (next == N) return res = 0;
  if (res >= 0) return res;
  res = 0;
  if (pattern & (1<<(P-1))) {
    int newpat = pattern ^ (1<<(P-1));
    newpat <<= 1;
    newpat |= 1;
    res += solve(next+1,newpat);
    res %= MOD;
  } else {
    REP(i,P) if (pattern & 1<<i) {
      int newpat = pattern ^ (1<<i);
      newpat <<= 1;
      newpat |= 1;
      res += solve(next+1,newpat);
      res %= MOD;
    }
  }
  return res;
}

int main() {
  getline(cin,Tline); stringstream(Tline) >> T;
  for (int t=1; t<=T; t++) {
    cin >> N >> K >> P;
    memset(ways,-1,sizeof(ways));
    printf("Case #%d: %d\n",t,solve(K,(1<<K)-1));
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
