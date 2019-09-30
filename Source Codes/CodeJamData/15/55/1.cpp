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
int rint() { int x; cin >> x; return x; }
LL rLL() { LL x; cin >> x; return x; }
string rstring() { string x; cin >> x; return x; }

int N,D;
vector<LL> v;
vector<LL> diff;

void ReadInput() {
  cin >> N >> D;
  v.clear(); REP(i,N) v.push_back(rLL());
}

LL Calc() {
  for(int i=2*D;i<N;++i) if(v[i]!=v[i-2*D]) throw 0;
  diff.resize(2*D);
  for(int i=0;i<2*D;++i) diff[i] = v[(i+1)%(2*D)] - v[i];
  LL res = 0;
  for(int d = D;d>=1;d>>=1) {
    vector<LL> on(2*d+1, 0);
    for(int i=0;i<d;++i) {
      LL a = diff[i+d]-diff[i];
      if(a>=0) {
        if(a%2) throw 0;
        a/=2;
        res += a;
        diff[i]+=a;
        diff[i+d]-=a;
        on[i+d+1]+=a;
        on[0]+=a;
        on[i+1]-=a;
      } else {
        a = -a;
        if(a%2) throw 0;
        a/=2;
        res += a;
        diff[i+d]+=a;
        diff[i]-=a;
        on[i+1]=a;
        on[i+1+d]-=a;
      }
    }
    LL s=0;
    REP(i,2*d) {
      LL x = on[i];
      s += x;
      v[i] -= s;
      if(v[i]<0) throw 0;
    }
  }
  return res;
}

int main(int argc, char **argv) {
  int ntc = rint();
  FOR(tc,1,ntc) {
    ReadInput();
    if(argc==2 && tc!=atoi(argv[1])) continue;
    cout << "Case #" << tc << ": ";
    try {
      auto res = Calc();
      cout << res << "\n";
    } catch(int) {
      cout << "CHEATERS!\n";
    }
  }
}
