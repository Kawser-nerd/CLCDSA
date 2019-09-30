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

int A[52][52];
int B[1004][1004];
int M;

bool check() {
  for (int i=(M+3)/2; i>=0; --i) {
    int lo = i, hi = M-1-i;
    for (int j=lo; j<=hi; ++j) {
      int P[4];
      P[0] = B[i][j];
      P[1] = B[j][i];
      P[2] = B[M-1-i][M-1-j];
      P[3] = B[M-1-j][M-1-i];
      REP(a,4) REP(b,a) if (P[b]!=-1 && P[a]!=-1 && P[a]!=P[b]) return false;
    }
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  FOR(t,1,T) {
    memset(B,-1,sizeof(B));
    int N;
    cin >> N;
    for (int s=0; s<N; ++s) for (int i=0; i<=s; ++i) cin >> A[i][s-i];
    for (int s=N; s<=2*N-2; ++s) for (int i=s-N+1; i<N; ++i) cin >> A[i][s-i];
    // REP(i,N) { REP(j,N) cout << A[i][j]; cout << endl; }
    for (int add=0; ; ++add) {
      bool ok = false;
      M = N + add;
      for (int dx=0; dx<=add; ++dx) {
        for (int dy=0; dy<=add; ++dy) {
          REP(i,N) REP(j,N) B[i+dx][j+dy] = A[i][j];
          if (check()) { ok = true; break; }
          REP(i,N) REP(j,N) B[i+dx][j+dy] = -1;
        }
        if (ok) break;
      }
      if (ok) { 
        //cerr << "add " << add << endl; 
        cout << "Case #" << t << ": " << (M*M-N*N) << endl; break; 
      }
    }
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
