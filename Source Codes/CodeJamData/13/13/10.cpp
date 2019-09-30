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
#define FOR(a,b,c) for(int a=(b); a<=(c); ++a)
 
template<class T>
inline int size(const T&t){return t.size();}

typedef long long LL;
 
//////////////////////////////////////////

int ile_liczb /* 3 */ , max_val /* 5 */, ile_wyn /* 7 */;
LL wyn[12];
int ile_w_wyn[10][12];
int min_w_wyn[10];
int guess[12];
double best;

int wyst[10];
int silnia[13];
int noverk[30][30];

int licznik;

void licz(int podziel) {
  ++licznik;
  if (licznik>1000000)
    throw 0;
  double pr = 1./podziel;
  REP(w, ile_wyn) {
    pr *= noverk[wyst[7]][ile_w_wyn[7][w]];
    pr *= noverk[wyst[5]][ile_w_wyn[5][w]];
    int x = 0;
    FOR(i6, 0, min(wyst[6], min(ile_w_wyn[3][w], ile_w_wyn[2][w]))) {
      int i3 = ile_w_wyn[3][w]-i6;
      if (i3>wyst[3]) continue;
      int pz2 = ile_w_wyn[2][w]-i6;
      FOR(i8, 0, min(wyst[8], pz2/3)) {
        int pz2_2 = pz2-i8*3;
        FOR(i4, 0, min(wyst[4], pz2_2/2)) {
          int i2 = pz2_2-i4*2;
          x += noverk[wyst[2]][i2]*noverk[wyst[3]][i3]*noverk[wyst[4]][i4]*noverk[wyst[6]][i6]*noverk[wyst[8]][i8];
        }
      }
    }
    pr *= x;
  }
  if (pr>best) {
    best = pr;
    int b = 0;
    FOR(a, 2, max_val)
      REP(x, wyst[a])
        guess[b++] = a;
  }
}

void gen(int start, int ile_zost, int podziel) {
  if (start==max_val) {
    wyst[start] = ile_zost;
    licz(podziel*silnia[wyst[start]]);
  }
  else {
    int x0 = 0;
    if (start==5) x0 = min_w_wyn[5];
    else
    if (start==6) x0 = min_w_wyn[3]-wyst[3];
    else
    if (start==7) x0 = min_w_wyn[7];

    for(wyst[start] = x0; wyst[start]<=ile_zost; ++wyst[start])
      gen(start+1, ile_zost-wyst[start], podziel*silnia[wyst[start]]);
  }
}

int dziel[] = {2,3,5,7};

int main() {
  int testow;
  scanf("%*d%d%d%d%d", &testow, &ile_liczb, &max_val, &ile_wyn);
  silnia[0] = 1;
  FOR(a, 1, 12)
    silnia[a] = silnia[a-1]*a;
  noverk[0][0] = 1;
  FOR(n, 1, 29)
    REP(k, n+1)
      noverk[n][k] = (k>0 ? noverk[n-1][k-1] : 0)+noverk[n-1][k];
  printf("Case #1:\n");
  REP(tt, testow) {
    REP(b, 4)
      min_w_wyn[dziel[b]] = 0;
    REP(a, ile_wyn) {
      scanf("%lld", &wyn[a]);
      REP(b, 4) {
        LL w = wyn[a];
        int x = 0;
        while (w%dziel[b]==0)
          w /= dziel[b], ++x;
        ile_w_wyn[dziel[b]][a] = x;
        min_w_wyn[dziel[b]] = max(min_w_wyn[dziel[b]], x);
      }
    }
    best = 0;
    licznik = 0;
    try {
    gen(2, ile_liczb, 1);
    } catch (...) {}
    fprintf(stderr, "         (%d)  %d\n", tt, licznik);
    REP(a, ile_liczb)
      printf("%d", guess[a]);
    printf("\n");
  }
}
