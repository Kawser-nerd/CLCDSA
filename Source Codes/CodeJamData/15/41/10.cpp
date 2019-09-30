//{{{
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << endl;

typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
template<class T> inline int size(const T&c) { return c.size(); }
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
LL rLL() { LL x; if(scanf("%lld",&x)!=1) return -1; return x; }
string rstring() { static char buf[100000]; if(scanf("%s",buf)!=1) return ""; return buf; }
//}}}

const int MAX = 128;

int SY,SX;
vector<string> board;

void ReadInput() {
  SY = rint();
  SX = rint();
  board.clear();
  REP(y,SY) board.push_back(rstring());
}

vector<vector<unsigned>> ok;

int Calc() {
  ok.assign(SY, vector<unsigned>(SX, 0u));

  REP(y,SY) {
    bool seen = false;
    REP(x,SX) {
      if(board[y][x] != '.') {
        if(seen) ok[y][x] |= 1u;
        seen = true;
      }
    }
  }

  REP(y,SY) {
    bool seen = false;
    FORD(x,SX-1, 0) {
      if(board[y][x] != '.') {
        if(seen) ok[y][x] |= 2u;
        seen = true;
      }
    }
  }

  REP(x,SX) {
    bool seen = false;
    REP(y,SY) {
      if(board[y][x] != '.') {
        if(seen) ok[y][x] |= 4u;
        seen = true;
      }
    }
  }

  REP(x,SX) {
    bool seen = false;
    FORD(y,SY-1,0) {
      if(board[y][x] != '.') {
        if(seen) ok[y][x] |= 8u;
        seen = true;
      }
    }
  }

  string s("<>^v");
  int res = 0;
  REP(y,SY) REP(x,SX) {
    if(board[y][x] != '.') {
      int a = find(s.begin(), s.end(), board[y][x]) - s.begin();
      assert(a>=0 && a<4);
      if(!(ok[y][x] & (1u<<a))) {
        if(!ok[y][x]) return -1;
        ++res;
      }
    }
  }
  return res;
}

int main(int argc, char **argv) {
  int ntc = rint();
  FOR(tc,1,ntc) {
    ReadInput();
    if(argc==2 && tc!=atoi(argv[1])) continue;
    int res = Calc();
    printf("Case #%d: ", tc);
    if(res==-1) printf("IMPOSSIBLE\n");
    else printf("%d\n", res);
  }
}

