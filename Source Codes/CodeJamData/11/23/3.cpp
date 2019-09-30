#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

int n;
VI g[2010];
int kolor[2010];

bool pomiedzy(int a, int b, int x){
  if (a < b) return (a < x && x < b);
  else return (a < x || x < b);
}

int nast(int a, int b){
  int c = (b+1)%n;
  if (c == a) return -1;
  FOREACH(it, g[b]){
    if (pomiedzy(c, a, *it))
      c = *it;
  }
  return c;
}

int koloruj(int k){
  REP(i,n) kolor[i] = -1;
  VPII v; v.PB(MP(0,1)); kolor[0] = 1; kolor[1] = 0;
  int minpole = 1000*1000;
  while (SIZE(v) > 0){
    PII x = v.back(); v.pop_back();
    int a = x.ST, b= x.ND, kol = (kolor[x.ND]+1)%k;
    if(kol == kolor[x.ST]) kol = (kol+1)%k;
    int pole = 2;
    while(1){
      int c = nast(a, b); if (c==-1) break;
      v.PB(MP(c, b));
      if (c == x.ST) break;
      kolor[c] = kol;
      kol = (kol+1)%k;
      if(kol == kolor[x.ST]) kol = (kol+1)%k;
      a = b; b = c; pole++;
    }
    if (pole > 2 && pole < minpole) minpole = pole;
  }
  return minpole;
}

int main(){
  int te; scanf("%d", &te);
  FOR(iii, 1, te){
    int m, a; scanf("%d%d", &n, &m); int dd[2010];
    REP(i, m) scanf("%d", &dd[i]); 
    REP(i, m){
      scanf("%d", &a); --a; --dd[i];
      g[a].PB(dd[i]);
      g[dd[i]].PB(a);
    }
    printf("Case #%d: %d\n", iii, koloruj(koloruj(100)));
    REP(i, n) printf("%d ", kolor[i]+1);
    printf("\n");
    REP(i, n) g[i].clear();
  }
  return 0;
}
