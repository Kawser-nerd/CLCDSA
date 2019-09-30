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


typedef __int128_t VLL;

struct Point {
  LL x,y;
  Point() {}
  Point(LL x,LL y):x(x),y(y) {}
};

inline Point operator+(const Point &A,const Point&B) { return Point(A.x+B.x,A.y+B.y); }
inline VLL operator%(const Point&A,const Point&B) { return VLL(A.x)*B.y-VLL(A.y)*B.x; }

struct Source {
  Point v;
  VLL cross;
};

bool operator<(const Source &a, const Source &b) {
  return a.cross < b.cross;
}

Point goal;
vector<Source> sources;

Point rPoint() {
  double a,b;
  int ret = scanf("%lf%lf", &a, &b);
  assert(ret==2);
  LL volume = LL(a * 10000 + 0.5);
  LL temp = LL(b * 10000 + 0.5);
  return Point(volume, volume * temp);
}

void ReadInput() {
  int n = rint();
  goal = rPoint();
  sources.resize(n);
  for(Source &s : sources) {
    s.v = rPoint();
    s.cross = goal % s.v;
  }
}

double Calc() {
  sort(sources.begin(), sources.end());
  VLL cross = 0;
  for(const Source &s : sources) cross += s.cross;
  if(cross < 0) {
    reverse(sources.begin(), sources.end());
    for(Source &s : sources) s.cross = - s.cross;
    cross = -cross;
  }
  int n=size(sources);
  while(cross>0) {
    assert(n>0);
    --n;
    cross -= sources[n].cross;
  }
  LL speed = 0;
  REP(i,n) speed += sources[i].v.x;
  double speed_d = double(speed);
  if(cross<0) speed_d += double(-cross) / double(sources[n].cross) * sources[n].v.x;
  if(speed_d <= 0.0) return -100;
  return double(goal.x) / speed_d;
}

int main(int argc, char **argv) {
  int ntc = rint();
  FOR(tc,1,ntc) {
    ReadInput();
    if(argc==2 && tc!=atoi(argv[1])) continue;
    double res = Calc();
    printf("Case #%d: ", tc);
    if(res < -0.5) printf("IMPOSSIBLE\n");
    else printf("%.15e\n", res);
  }
}

