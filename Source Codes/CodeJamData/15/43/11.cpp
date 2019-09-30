//{{{
#include <algorithm>
#include <bitset>
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
//}}}

int nwords;
map<string,int> words;
vector<vector<int>> sentences;

void ReadInput() {
  int n; cin >> n;
  string line; getline(cin,line);
  nwords = 0;
  words.clear();
  sentences.clear();
  REP(i,n) {
    getline(cin, line);
    stringstream ss(line);
    string w;
    vector<int> sentence;
    while(ss >> w) {
      if(!words.count(w)) words[w] = nwords++;
      sentence.push_back(words[w]);
    }
    sentences.push_back(sentence);
  }
}

int Count(bitset<200> &s2) {
  vector<unsigned> v(nwords, 0u);
  REP(i, size(sentences)) {
    unsigned m = s2[i] ? 1u : 2u;
    for(int x : sentences[i]) v[x] |= m;
  }
  int cnt = 0;
  for(auto a : v) if(a==3u) ++cnt;
  return cnt;
}

int Calc() {
  int res = nwords;
  mt19937 rnd(120);
  auto st = clock();
  while(clock()-st < 6 * CLOCKS_PER_SEC) {
    bitset<200> s;
    s[0] = 1;
    s[1] = 0;
    for(int i=2;i<size(sentences);++i) s[i]=rnd()&1;
    int c = Count(s);
    for(;;) {
      bool improvement=false;
      FOR(i,2,size(sentences)-1) {
        s[i] = !s[i];
        int c2 = Count(s);
        if(c2<c) {
          improvement=true;
          c =c2;
        } else {
          s[i]=!s[i];
        }
      }
      if(!improvement) break;
    }
    res = min(res, c);
  }
  return res;
}

int main(int argc, char **argv) {
  int ntc; cin >> ntc;
  FOR(tc,1,ntc) {
    ReadInput();
    if(argc==2 && tc!=atoi(argv[1])) continue;
    auto res = Calc();
    printf("Case #%d: %d\n", tc, res);
  }
}

