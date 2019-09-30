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

const string names[10] = {
  "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE",
};

vector<pair<char, int>> mapping;

void ComputeMapping() {
  unsigned unseen = (1u << 10) - 1u;
  while(unseen) {
    for(char c='A'; c<='Z';++c) {
      unsigned where = 0;
      for(int d=0;d<10;++d) {
        for(char e:names[d]) {
          if(e==c) where |= 1u << d;
        }
      }
      where &= unseen;
      if (where != 0u && (where &(where-1))==0u) {
        int where1 = __builtin_ctz(where);
        cerr << c << " -> " << where1 << endl;
        mapping.push_back({c, where1});
        unseen ^= where;
        goto found;
      }
    }
    cerr << "nothing!\n";
    assert(false);
found:;
  }
}

int cnt[26];

void ReadInput() {
  string s; cin >> s;
  memset(cnt, 0, sizeof(cnt));
  for (char c : s) ++cnt[c-'A'];
}

string Calc() {
  int res[10] = {};
  for (auto m : mapping) {
    char c = m.first;
    int d = m.second;
    while(cnt[c-'A'] > 0) {
      ++res[d];
      for (char e : names[d]) --cnt[e-'A'];
    }
  }
  REP(i,26) {
    assert(cnt[i]==0);
  }
  string resS;
  REP(d,10) REP(i,res[d]) resS += char('0'+d);
  return resS;
}

int main(int argc, char **argv) {
  ComputeMapping();
  int ntc; cin >> ntc;
  FOR(tc,1,ntc) {
    ReadInput();
    if(argc==2 && tc!=atoi(argv[1])) continue;
    auto res = Calc();
    cout << "Case #" << tc << ": " << res << "\n";
  }
}

