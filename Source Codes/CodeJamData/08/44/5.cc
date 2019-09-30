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
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

#include <cstring>
int G[20][20];
int K;
string S;
int prvy, posledny;

int memo[20][70000];

int solve(int last, int unused) {
  int &res = memo[last][unused];
  if (res >= 0) return res;
  if (unused == 0) return res = G[last][posledny];
  res = 0;
  REP(next,K) if (unused & (1<<next)) res = max( res, G[last][next] + solve(next,unused ^ (1<<next)) );
  return res;
}

int main() {
  int T;
  cin >> T;
  FOR(t,1,T) {
    memset(G,0,sizeof(G));
    cin >> K >> S;
    int N = SIZE(S);
    REP(b,N/K) {
      REP(i,K) REP(j,i) if (S[b*K+i]==S[b*K+j]) { G[i][j]++; G[j][i]++; }
    }
    int res = SIZE(S);
    for (prvy=0; prvy<K; prvy++) for (posledny=0; posledny<K; posledny++) if (prvy!=posledny) {
      int toto = SIZE(S);
      REP(b,(N/K)-1) if (S[b*K+posledny]==S[b*K+K+prvy]) toto--;
      memset(memo,-1,sizeof(memo));
      toto -= solve(prvy,((1<<K)-1) ^ (1<<prvy) ^ (1<<posledny));
      res = min( res, toto );
    }
    printf("Case #%d: %d\n",t,res);
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
