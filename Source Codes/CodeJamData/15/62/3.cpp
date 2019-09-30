//{{{
#include <bits/stdc++.h>
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

typedef Modulo<1000000007> Mod;

int N,X;

void ReadInput() {
  cin >> N >> X;
}

Mod Calc() {
  vector<Mod> f(N+1);
  vector<Mod> g(N+1);
  vector<Mod> fact(N+1);
  g[0] = 0;
  f[0] = 1;
  fact[0] = 1;
  FOR(i,1,N) {
    g[i] = f[i-1] + Mod(i-1) * g[i-1];
    f[i] = Mod(i-1) * g[i-1];
    fact[i] = fact[i-1]*Mod(i);
  }
  Mod res = 0;
  FOR(i,X,N) {
    res += fact[N] * f[N-i] / (fact[i] * fact[N-i]);
  }
  res *= fact[N];
  return res;
}

int main(int argc, char **argv) {
  int ntc = rint();
  FOR(tc,1,ntc) {
    ReadInput();
    if(argc==2 && tc!=atoi(argv[1])) continue;
    auto res = Calc();
    cout << "Case #" << tc << ": " << res.get() << "\n";
  }
}

