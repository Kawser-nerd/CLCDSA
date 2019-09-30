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
 
#define INF 1000000000

typedef long long LL; 

template<class T>
inline int size(const T&t){return t.size();}
 
//////////////////////////////////////////

LL R, F;

LL licz() {
  LL ok = 1, nieok = 2*INF;
  while (nieok-ok>1) {
    LL k = ok+(nieok-ok)/2;
    LL pot = k*(2*R+2*k-1);
    ((pot/k==2*R+2*k-1 && pot<=F) ? ok : nieok) = k;
  }
  return ok;
}

int main() {
  int TT;
  scanf("%d ", &TT);
  REP(tt, TT) {
    scanf("%lld%lld", &R, &F);
    printf("Case #%d: %lld\n", tt+1, licz());
  }
}
