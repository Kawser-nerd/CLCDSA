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
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

#define WALL 1
#define GOAL 2
#define BOX 4

int mapa[16][16];
int R, C;
map< vector<int>, int > dist;
int dr[]={-1,1,0,0}, dc[]={0,0,-1,1};

inline bool empty(int r, int c) {
  if (mapa[r][c] & WALL) return false;
  if (mapa[r][c] & BOX) return false;
  return true;
}

vector<int> pack() {
  vector<int> res;
  FOR(r,1,R) FOR(c,1,C) if (mapa[r][c] & BOX) res.push_back( (r<<5) | c );
  return res;
}

void unpack(const vector<int> &boxes) {
  FOR(r,1,R) FOR(c,1,C) mapa[r][c] &= ~BOX;
  REP(i,SIZE(boxes)) {
    int c = boxes[i] & 31;
    int r = boxes[i] >> 5;
    mapa[r][c] |= BOX;
  }
}

bool danger() {
  int v[16][16];
  FOR(r,1,R) FOR(c,1,C) v[r][c]=0;
  int sr,sc;
  for (sr=1; sr<=R; ++sr) {
    for (sc=1; sc<=C; ++sc) {
      if (mapa[sr][sc] & BOX) break;
    }
    if (mapa[sr][sc] & BOX) break;
  }
  v[sr][sc] = 1;
  queue<int> Q;
  Q.push(sr); Q.push(sc);
  while (!Q.empty()) {
    int r=Q.front(); Q.pop();
    int c=Q.front(); Q.pop();
    REP(d,4) {
      int nr=r+dr[d], nc=c+dc[d];
      if (mapa[nr][nc] & BOX) if (!v[nr][nc]) {
        v[nr][nc] = 1;
        Q.push(nr);
        Q.push(nc);
      }
    }
  }
  FOR(r,1,R) FOR(c,1,C) if (mapa[r][c] & BOX) if (v[r][c]==0) return true;
  return false;
}

int main() {
  int T;
  cin >> T;
  FOR(ttt,1,T) {
    REP(r,16) REP(c,16) mapa[r][c]=1;
    cin >> R >> C;
    string line;
    FOR(r,1,R) { 
      cin >> line;
      FOR(c,1,C) {
        if (line[c-1]=='.') mapa[r][c]=0;
        if (line[c-1]=='#') mapa[r][c]=1;
        if (line[c-1]=='x') mapa[r][c]=2;
        if (line[c-1]=='o') mapa[r][c]=4;
        if (line[c-1]=='w') mapa[r][c]=6;
      }
    }
    dist.clear();
    dist[ pack() ] = 0;
    queue< vector<int> > Q;
    Q.push( pack() );
    while (!Q.empty()) {
      unpack( Q.front() );
      int ddd = dist[ Q.front() ];
      Q.pop();
      bool dan = danger();
      FOR(r,1,R) FOR(c,1,C) if (mapa[r][c] & BOX) {
        REP(d,4) {
          if (!empty(r+dr[d],c+dc[d])) continue;
          if (!empty(r-dr[d],c-dc[d])) continue;
          mapa[r][c] &= ~BOX;
          mapa[r+dr[d]][c+dc[d]] |= BOX;
          bool dan2 = danger();
          if (!dan || !dan2) {
            vector<int> next = pack();
            if (!dist.count(next)) {
              dist[next] = ddd+1;
              Q.push(next);
            }
          }
          mapa[r][c] |= BOX;
          mapa[r+dr[d]][c+dc[d]] &= ~BOX;
        }
      }
    }
    FOR(r,1,R) FOR(c,1,C) mapa[r][c] &= ~BOX;
    FOR(r,1,R) FOR(c,1,C) if (mapa[r][c] & GOAL) mapa[r][c] |= BOX;
    vector<int> target = pack();
    if (dist.count(target)) {
      printf("Case #%d: %d\n",ttt,dist[target]);
    } else {
      printf("Case #%d: -1\n",ttt);
    }
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
