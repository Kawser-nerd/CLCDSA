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
#define CLEAR(t) memset((t),0,sizeof(t))
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

#define MAX 12800
#define CENTER 6400

#define SETA(A,x,y) A[x][(y)>>3] |= (1<<((y)&7))
#define GETA(A,x,y) (A[x][(y)>>3] & (1<<((y)&7)))
#define SET(A,x,y) A[(x)>>1][(y)>>4] |= (1<<(((y)>>1)&7))
#define GET(A,x,y) (A[(x)>>1][(y)>>4] & (1<<(((y)>>1)&7)))

unsigned char A[MAX][MAX/8], O[MAX][MAX/8], L[MAX/2][MAX/16], R[MAX/2][MAX/16], T[MAX/2][MAX/16], B[MAX/2][MAX/16];
int dx[] = {0,1,0,-1}, dy[] = { -1,0,1,0 };

int main() {
  int TT;
  cin >> TT;
  FOR(t,1,TT) {
    int IC;
    cin >> IC;
    CLEAR(A);
    int X = CENTER, Y = CENTER, D = 0;
    int mx=X, Mx=X, my=Y, My=Y;
    while (IC--) {
      string cmd; int tms;
      cin >> cmd >> tms;
      while (tms--) {
        REP(i,SIZE(cmd)) {
          if (cmd[i]=='L') D = (D+3)%4;
          if (cmd[i]=='R') D = (D+1)%4;
          if (cmd[i]=='F') {
            X += dx[D];
            Y += dy[D];
            SETA(A,X,Y);
            X += dx[D];
            Y += dy[D];
            SETA(A,X,Y);
            mx = min(mx,X);
            my = min(my,Y);
            Mx = max(Mx,X);
            My = max(My,Y);
          }
        }
      }
    }
    // REP(y,MAX) { REP(x,MAX) cout << (GET(A,x,y)?'x':'.'); cout << endl; }
    mx--; Mx++; my--; My++;
    CLEAR(O);
    queue<int> Q;
    Q.push(mx); Q.push(my); SETA(O,0,0);
    int sets=0;
    while (!Q.empty()) {
      int x=Q.front(); Q.pop();
      int y=Q.front(); Q.pop();
      REP(d,4) {
        int nx=x+dx[d], ny=y+dy[d];
        if (nx<mx || nx>Mx || ny<my || ny>My) continue;
        if (GETA(O,nx,ny)) continue;
        if (GETA(A,nx,ny)) continue;
        SETA(O,nx,ny);
        Q.push(nx); Q.push(ny);
        sets++;
      }
    }
    // cout << sets << endl;
    // REP(y,MAX) { REP(x,MAX) cout << (GET(O,x,y)?'F':'.'); cout << endl; }
    CLEAR(L);
    CLEAR(R);
    CLEAR(T);
    CLEAR(B);
    for (int x=1; x<MAX; x+=2) {
      for (int y=1; y<MAX; y+=2) {
        if (GETA(O,x,y) && GETA(A,x,y-1)) SET(T,x,y);
        if (GETA(O,x,y) && y>1 && GET(T,x,y-2)) SET(T,x,y);
      }
      for (int y=MAX-1; y>=0; y-=2) {
        if (GETA(O,x,y) && GETA(A,x,y+1)) SET(B,x,y);
        if (GETA(O,x,y) && y<MAX-1 && GET(B,x,y+2)) SET(B,x,y);
      }
    }
    for (int y=1; y<MAX; y+=2) {
      for (int x=1; x<MAX; x+=2) {
        if (GETA(O,x,y) && GETA(A,x-1,y)) SET(L,x,y);
        if (GETA(O,x,y) && x>1 && GET(L,x-2,y)) SET(L,x,y);
      }
      for (int x=MAX-1; x>=0; x-=2) {
        if (GETA(O,x,y) && GETA(A,x+1,y)) SET(R,x,y);
        if (GETA(O,x,y) && x<MAX-1 && GET(R,x+2,y)) SET(R,x,y);
      }
    }
    int res = 0;
    for (int x=1; x<MAX; x+=2) for (int y=1; y<MAX; y+=2) if (GETA(O,x,y)) {
      int ok = 0;
      if (GET(L,x,y) && GET(R,x,y)) ok=1;
      if (GET(T,x,y) && GET(B,x,y)) ok=1;
      res += ok;
    }
    printf("Case #%d: %d\n",t,res);
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
