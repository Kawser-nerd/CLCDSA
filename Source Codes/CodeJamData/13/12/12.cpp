#include <string>
#include <vector>
#include <cmath> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
 
using namespace std;
 
#define REP(a,n) for(int a=0; a<(n); ++a)
#define FORD(a,b,c) for(int a=(b); a>=(c); --a)
#define VAR(x, v) __typeof(v) x = (v);
#define MP make_pair

typedef long long LL;
typedef pair<int, int> pii;
 
template<class T>
inline int size(const T&t){return t.size();}
 
//////////////////////////////////////////

int E, R, N, val[10000];

LL licz() {
  LL wyn = 0;
  set<int> uzyte;
  pii pary[10000];
  REP(a, N)
    pary[a] = MP(-val[a], a);
  sort(pary, pary+N);
  REP(a, N) {
    int nr = pary[a].second;
    uzyte.insert(nr);
    int mogemax = E;
    VAR(it, uzyte.find(nr));
    if (it!=uzyte.begin()) {
      --it;
      int pop = *it;
      ++it;
      mogemax = min((LL)E, (nr-pop)*(LL)R);
    }
    ++it;
    int mogemin = 0;
    if (it!=uzyte.end()) {
      int next = *it;
      mogemin = max((LL)0, E-(next-nr)*(LL)R);
    }
    if (mogemax>mogemin)
      wyn += (mogemax-mogemin)*(LL)val[nr];
  }
  return wyn;
}

int main() {
  int TT;
  scanf("%d ", &TT);
  REP(tt, TT) {
    scanf("%d%d%d", &E, &R, &N);
    REP(x, N)
      scanf("%d", &val[x]);
    printf("Case #%d: %lld\n", tt+1, licz());
  }
}
