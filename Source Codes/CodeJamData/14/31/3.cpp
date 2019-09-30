#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

LL gcd(LL a, LL b) {
  return b ? gcd(b, a%b) : a;
}

void scase() {
  LL P,Q;
  scanf("%lld/%lld", &P, &Q);

  LL d = gcd(P,Q);
  P /= d;
  Q /= d;
  
  if (Q&(Q-1)) {
    printf("impossible\n");
    return;
  }
  
  LL p1 = 1;
  while (p1 * 2 <= P) p1 *= 2;
  
  LL x = Q / p1;
  int result = -1;
  while (x) {
    x /= 2;
    ++result;
  }
  
  printf("%d\n", result);
}

int main() {
  int Z;
  scanf("%d", &Z);
  REP(z,Z) {
    printf("Case #%d: ", z+1);
    scase();
  }
}    
