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

template<class T>
T mypower(T a, ULL b) {
  T res = T(1);
  while(b) {
    if(b&1u) res *= a;
    b >>= 1;
    a = a*a;
  }
  return res;
}

template<unsigned MOD>
class Modulo {
  unsigned v;
 public:
  Modulo() {}
  Modulo(unsigned x):v(x%MOD) {}
  int get() const { return v; }
  Modulo operator+(Modulo b) const { return Modulo(v+b.v); }
  void operator+=(Modulo b) { *this = *this + b; }
  Modulo operator-(Modulo b) const { return Modulo(v+MOD-b.v); }
  void operator-=(Modulo b) { *this = *this - b; }
  Modulo operator*(Modulo b) const { return Modulo(unsigned(ULL(v) * ULL(b.v) % MOD)); }
  void operator*=(Modulo b) { *this = *this * b; }
  Modulo operator/(Modulo b) const { return *this * b.inverse(); }
  void operator/=(Modulo b) { *this = *this / b; }
  Modulo inverse() const { return mypower(*this, MOD-2); }
};

const unsigned PRIME = 1000000007u;

typedef Modulo<PRIME> Mod;

int SY, SX;

void ReadInput() {
  SY = rint();
  SX = rint();
}

map<pair<int,int>,Mod> cacheNo3;

Mod Calc3(int,int);

Mod CalcNo3(int sy, int sx) {
  pair<int,int> h {sy,sx};
  if(cacheNo3.count(h)) return cacheNo3[h];
  Mod res = 0;
  if(sy==0) res = 1;
  if(sy>=1) res += Calc3(sy-1, sx);
  if(sy>=2 && sx%3==0) {
    res += Mod(3) * Calc3(sy-2, sx);
  }
  if(sy>=2 && sx%6==0) {
    res += Mod(6) * Calc3(sy-2, sx);
  }
  if(sy>=3 && sx%4==0) {
    res += Mod(4) * Calc3(sy-3, sx);
  }
  cacheNo3[h] = res;
  return res;
}

Mod Calc3(int sy, int sx) {
  if(sy<0) return 0;
  if(sy==0) return 1;
  return CalcNo3(sy-2, sx);
}

Mod Calc(int sy, int sx) {
  return CalcNo3(sy, sx) + Calc3(sy, sx);
}

int Calc() {
  Mod cnt[13];
  Mod sum = 0;
  FOR(i,1,12) {
    cnt[i] = 0;
    if(SX % i != 0) continue;
    cnt[i] = Calc(SY, i);
    //cerr << i << " -> " << cnt[i].get() << "\n";
    FOR(j,1,i-1) if(i%j==0) cnt[i] -= cnt[j];
    //cerr << i << " -> " << cnt[i].get() << "\n";
    sum += cnt[i] / i;
  }
  return sum.get();
}

int main(int argc, char **argv) {
  int ntc = rint();
  FOR(tc,1,ntc) {
    ReadInput();
    if(argc==2 && tc!=atoi(argv[1])) continue;
    auto res = Calc();
    printf("Case #%d: %d\n", tc, res);
  }
}

