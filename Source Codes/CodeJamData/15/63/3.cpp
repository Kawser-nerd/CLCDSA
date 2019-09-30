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

typedef __int128_t VLL;

string text;
LL F; // 0..10^18

void ReadInput() {
  int N;
  double f;
  cin >> N >> f;
  cin >> text;
  assert(size(text)==N);
  int f2 = int(f * 1000000 + 0.5);
  F = f2 * 1000000000000LL;
}

vector<pair<VLL,int>> Walk(LL F2) {
  int n = size(text);
  vector<pair<VLL,int>> res;
  res.reserve(n+1);
  VLL s = 0;
  const LL big = 1000000000000000000LL;
  REP(i,n) {
    res.push_back(make_pair(s, i));
    s += (text[i]-'0') * big - F2;
  }
  res.push_back(make_pair(s, n));
  return res;
}

// set res only if true
bool Check(LL eps, int &res) {
  vector<pair<VLL,int>> A = Walk(F+eps);
  vector<pair<VLL,int>> B = Walk(F-eps);
  for(auto &a : A) a.second = -a.second;
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  for(auto &a : A) a.second = -a.second;
  int best = INF;
  REP(i,size(A)) if(A[i].second != B[i].second) {
    best = min(best, A[i].second);
  }
  if(best!=INF) { res = best; return true; }
  else return false;
}

int Calc() {
  int res = -1;
  LL epsBad = -1;
  LL epsGood = 0;
  while(!Check(epsGood, res)) {
    LL diff = epsGood - epsBad;
    epsBad = epsGood;
    epsGood += 2*diff;
  }
  while(epsGood-epsBad>1) {
    LL eps = epsBad + (epsGood-epsBad)/2;
    if(Check(eps, res)) {
      epsGood = eps;
    } else {
      epsBad = eps;
    }
  }
  return res;
}

int main(int argc, char **argv) {
  int ntc; cin >> ntc;
  FOR(tc,1,ntc) {
    ReadInput();
    if(argc==2 && tc!=atoi(argv[1])) continue;
    auto res = Calc();
    cout << "Case #" << tc << ": " << res << "\n";
  }
}

