#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define FOR(prom, a, b) for(int prom = (a); prom < (b); prom++)
#define FORD(prom, a, b) for(int prom = (a); prom > (b); prom--)
#define FORDE(prom, a, b) for(int prom = (a); prom >= (b); prom--)

#define DRI(a) int a; scanf("%d ", &a);
#define DRII(a, b) int a, b; scanf("%d %d ", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d ", &a, &b, &c);
#define DRIIII(a, b, c, d) int a, b, c, d; scanf("%d %d %d %d ", &a, &b, &c, &d);
#define RI(a) scanf("%d ", &a);
#define RII(a, b) scanf("%d %d ", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d ", &a, &b, &c);
#define RIIII(a, b, c, d) scanf("%d %d %d %d ", &a, &b, &c, &d);

#define PB push_back
#define MP make_pair

#define ll long long
#define ull unsigned long long

#define MM(co, cim) memset((co), (cim), sizeof((co)))

#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;

// no additional code, but a hell lot of paper, could have seen that sooner ^^

int main ()
{
  DRI(T);
  FOR(t,0,T) {
    DRIII(X,R,C);
    if((R * C) % X != 0) {
      printf("Case #%d: RICHARD\n", t+1);
      continue;
    }
    if(X == 1) {
      printf("Case #%d: GABRIEL\n", t+1);
    } else if(X == 2) {
      printf("Case #%d: GABRIEL\n", t+1);
    } else if(X == 3) {
      if(R <= 1 || C <= 1) printf("Case #%d: RICHARD\n", t+1);
      else printf("Case #%d: GABRIEL\n", t+1);
    } else if(X == 4) {
      if(R <= 2 || C <= 2) printf("Case #%d: RICHARD\n", t+1);
      else printf("Case #%d: GABRIEL\n", t+1);
    } else if(X == 5) {
      if(R <= 2 || C <= 2 || R*C == 15) printf("Case #%d: RICHARD\n", t+1);
      else printf("Case #%d: GABRIEL\n", t+1);
    } else if(X == 6) {
      if(R <= 3 || C <= 3) printf("Case #%d: RICHARD\n", t+1);
      else printf("Case #%d: GABRIEL\n", t+1);
    } else {
      printf("Case #%d: RICHARD\n", t+1);
    }
  }
  return 0;
}
