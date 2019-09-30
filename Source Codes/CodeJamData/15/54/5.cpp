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

struct Multi {
  LL v;
  LL cnt;
};

typedef vector<Multi> Multiset;

Multiset SS;

void ReadInput() {
  int P; cin >> P;
  SS.resize(P);
  REP(i,P) cin >> SS[i].v;
  REP(i,P) cin >> SS[i].cnt;
}

bool Contains0(const Multiset &S) {
  int p=0;
  while(p<size(S) && S[p].v <0) ++p;
  return p<size(S) && S[p].v==0;
}

bool Split(Multiset S, Multiset &A, Multiset &B, LL diff) {
  A.clear();
  B.clear();
  int q=0;
  for(int p=0;p<size(S);++p) {
    if(S[p].cnt==0) continue;
    while(q<size(S) && S[q].v < S[p].v+diff) ++q;
    if(q==size(S) || S[q].v != S[p].v+diff || S[q].cnt < S[p].cnt) return false;
    Multi m = S[p];
    A.push_back(m);
    m.v += diff;
    B.push_back(m);
    S[q].cnt -= S[p].cnt;
    S[p].cnt=0;
  }
  return true;
}

bool Split0(const Multiset &S, Multiset &A) {
  A = S;
  for(Multi &m : A) {
    if(m.cnt & 1) return false;
    m.cnt >>= 1;
  }
  return true;
}

bool Search(const Multiset &S, vector<LL> &res, LL minNext) {
  if(S[0].v < 0) {
    for(const auto &m : S) {
      LL candidate = m.v;
      if(candidate<minNext) continue;
      if(candidate>=0) break;
      Multiset A,B;
      if(Split(S,A,B,-candidate)) {
        if(Contains0(B)) {
          res.push_back(candidate);
          if(Search(B, res, candidate)) return true;
          res.pop_back();
        }
      }
    }
    return false;
  } else {
    assert(S[0].v == 0);
    if(S[0].cnt > 1) {
      Multiset A;
      assert(0 >= minNext);
      if(Split0(S,A)) {
        res.push_back(0);
        if(Search(A, res, 0)) return true;
        res.pop_back();
      }
      return false;
    } else if(size(S)==1) {
      return true;
    } else {
      LL candidate = S[1].v;
      assert(candidate >= minNext);
      Multiset A,B;
      if(Split(S,A,B, candidate)) {
        res.push_back(candidate);
        if(Search(A, res, candidate)) return true;
        res.pop_back();
      }
      return false;
    }
  }
}

vector<LL> Calc() {
  vector<LL> res;
  bool found = Search(SS, res, -1e18);
  assert(found);
  return res;
}

int main(int argc, char **argv) {
  int ntc = rint();
  FOR(tc,1,ntc) {
    ReadInput();
    if(argc==2 && tc!=atoi(argv[1])) continue;
    vector<LL> res = Calc();
    cout << "Case #" << tc << ":";
    for(LL x : res) cout << " " << x;
    cout << "\n";
  }
}
