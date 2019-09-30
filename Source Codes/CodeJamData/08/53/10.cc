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
/*
  compute the size of a maximum matching in the bipartite graph G
	G[i][j] = (are part1[i] and part2[j] connected?)
*/
int BIPARTITE_MATCHING_SIZE(const vector< vector<int> > G) {
  int A = G.size(), B = G[0].size();
  
  vector<int> matched(A,0), match(A,0);

  for (int j=0; j<B; j++) {
    vector<int> seen(A,0), from(A,-1);
    
    queue<int> Q;
    for (int i=0; i<A; i++) if (G[i][j]) { Q.push(i); seen[i]=1; }
    int found = 0;
    
    while (!Q.empty()) {
      int where = Q.front(); Q.pop();
      if (!matched[where]) {
        found = 1;
        // update
        matched[where]=1;
        while (1) {
          if (from[where]==-1) { match[where]=j; break; }
          match[where] = match[ from[where] ];
          where = from[where];
        }
        break; // stop looking (this is necessary)!
      }
      
      int neighbor = match[where];
      for (int i=0; i<A; i++) if (G[i][neighbor]) if (!seen[i]) { Q.push(i); seen[i]=1; from[i]=where; }
    }
  }
  int res = 0;
  for (int i=0; i<A; i++) res += matched[i];
  return res;
}
#define CLEAR(t) memset((t),0,sizeof(t))
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int M[120][120], X[120][120];
int R,C,A,B;
int dr[]={0,0,-1,-1}, dc[]={-1,1,-1,1};

int main() {
  int T;
  cin >> T;
  FOR(t,1,T) {
    CLEAR(M);
    cin >> R >> C;
    REP(r,R) { string S; cin >> S; REP(c,C) M[r][c] = S[c]=='.'; }
    A = 0;
    B = 0;
    REP(r,R) for (int c=0; c<C; c+=2) if (M[r][c]) X[r][c]=A++;
    REP(r,R) for (int c=1; c<C; c+=2) if (M[r][c]) X[r][c]=B++;
    vector< vector<int> > G(A,B);
    REP(r,R) REP(c,C) if (M[r][c]) REP(d,4) {
      int nr=r+dr[d], nc=c+dc[d];
      if (nr<0 || nr>=R || nc<0 || nc>=C) continue;
      if (!M[nr][nc]) continue;
      int x=X[r][c], y=X[nr][nc];
      if (c%2) swap(x,y);
      G[x][y]=1;
    }
    int res = A + B - BIPARTITE_MATCHING_SIZE(G);
    printf("Case #%d: %d\n",t,res);
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
