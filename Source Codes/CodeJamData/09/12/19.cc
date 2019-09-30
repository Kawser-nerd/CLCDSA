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
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

typedef pair<int,int> pozicia;
typedef pair<long long,pozicia> record;
int TTT, N, M;
long long S[100][100], W[100][100], T[100][100], dist[100][100];

long long next_green(long long _now, int r, int c, bool vertical) {
  long long now = _now;
  now -= T[r][c];
  now %= (S[r][c] + W[r][c]);
  now += (S[r][c] + W[r][c]);
  now %= (S[r][c] + W[r][c]);
  if (vertical) {
    if (now < S[r][c]) return _now;
    return _now + (S[r][c] + W[r][c] - now);
  } else {
    if (now >= S[r][c]) return _now;
    return _now + (S[r][c] - now);
  }
}

int dr[]={-1,1,0,0}, dc[]={0,0,-1,1};
bool dvert[]={true,true,false,false};

int main() {
  cin >> TTT;
  for (int ttt=1; ttt<=TTT; ++ttt) {
    cin >> N >> M;
    for (int n=0; n<N; ++n) for (int m=0; m<M; ++m) cin >> S[n][m] >> W[n][m] >> T[n][m];
    for (int n=0; n<2*N; ++n) for (int m=0; m<2*M; ++m) dist[n][m] = 123456789012345LL;
    dist[2*N-1][0] = 0;
    priority_queue< record, vector<record>, greater<record> > Q;
    Q.push(record(0,pozicia(2*N-1,0)));
    while (!Q.empty()) {
      int r = Q.top().second.first;
      int c = Q.top().second.second;
      long long D = Q.top().first;
      Q.pop();
      if (D > dist[r][c]) continue;
      if (r==0 && c==2*M-1) break;
      for (int d=0; d<4; ++d) {
        int nr=r+dr[d], nc=c+dc[d], nv=dvert[d];
        if (nr<0 || nc<0 || nr>=2*N || nc>=2*M) continue;
        if ( ((nr^r)<=1) && ((nc^c)<=1) ) {
          // crossing
          long long dd = next_green(D,nr/2,nc/2,nv) + 1;
          if (dd < dist[nr][nc]) {
            dist[nr][nc] = dd;
            Q.push(record(dd,pozicia(nr,nc)));
          }
        } else {
          // moving
          if (D+2 < dist[nr][nc]) {
            dist[nr][nc] = D+2;
            Q.push(record(D+2,pozicia(nr,nc)));
          }
        }
      }
    }
    cout << "Case #" << ttt << ": " << dist[0][2*M-1] << endl;
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
