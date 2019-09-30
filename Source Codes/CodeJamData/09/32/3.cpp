#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

/* PREWRITTEN CODE */

#define ALL(x) x.begin(),x.end()
#define PB push_back


#define FOR(i,p,k) for (int i=p; i<k; i++)
#define REP(i,n) for (int i=0; i<n; i++)
#define SIZE(x) (int)x.size()
#define EPS 0.000000001
/* COMPETITION CODE */

typedef long double ld;
    
typedef struct pt {
  ld s[3];
} pt;

#define X s[0]
#define Y s[1]
#define Z s[2]

pt operator+ (const pt &A, const pt &B) {
  pt P;
  P.X = A.X + B.X;
  P.Y = A.Y + B.Y;
  P.Z = A.Z + B.Z;
  return P;
}

pt operator- (const pt &A, const pt &B) {
  pt P;
  P.X = A.X - B.X;
  P.Y = A.Y - B.Y;
  P.Z = A.Z - B.Z;
  return P;
}

pt operator* (ld l, const pt &B) {
  pt P;
  P.X = l * B.X;
  P.Y = l * B.Y;
  P.Z = l * B.Z;
  return P;
}

void zero (pt &P) {
  P.X = P.Y = P.Z = 0.;
}

ld is (const pt &A, const pt &B) {
  ld tot = 0.;
  REP (i, 3) tot += A.s[i] * B.s[i];
  return tot;
}

ld lgt (const pt &A) {
  return sqrtl(is(A,A));
}

int main () {
  int T;
  scanf("%d", &T);
  REP (tests, T) {
    pt F,V,cF,cV;
    int N;
    zero(F); zero(V);
    scanf("%d", &N);
    REP (i, N) {
      REP (j, 3) scanf("%Lf", &cF.s[j]);
      F = F - cF; // Turn around the origin
      REP (j, 3) scanf("%Lf", &cV.s[j]);
      V = V + cV;
    }
    F = ((ld) (1.0 / (ld) N)) * F;
    V = ((ld) (1.0 / (ld) N)) * V;
//    printf("%Lf %Lf %Lf -- %Lf %Lf %Lf\n", F.X, F.Y, F.Z, V.X, V.Y, V.Z);
    if (is(V,F) <= EPS) {
      printf("Case #%d: %.8Lf 0.0000000\n", tests+1, lgt(F));
    } else {
      ld t = is(V,F) / is(V,V);
      pt M = t * V;
      ld d = lgt(M - F);
      printf("Case #%d: %.8Lf %.8Lf\n", tests+1, d, t);
    }
  }
  return 0;
}

