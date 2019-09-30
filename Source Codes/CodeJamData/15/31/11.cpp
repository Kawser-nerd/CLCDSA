#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int mozne[1<<20];
int stavy[1<<20];

#define GET(s,i) (!!( (s) & (1<<(i)) ))

int getrec(int C, int W, int s) {
  if (stavy[s] != -1) return stavy[s];
  int best = 200000;
  for (int ja = 0; ja < C; ja++) {
    if (GET(s, ja)) continue;
    int povievolnostav = s | (1<<ja);
    int povievolno = mozne[povievolnostav] ? 1+getrec(C, W, povievolnostav) : 0;
    int tesne = (ja == 0 || ja == C-1 || GET(s, ja-1) || GET(s, ja+1));
    int poviezasah = W + (tesne ? 0 : 1);
    best = min(best, max(poviezasah, povievolno));
  }
  stavy[s] = best;
  return best;
}

int getlast(int C, int W) {
  for (int s = 0; s < (1<<C); s++) stavy[s] = -1;
  for (int s = 0; s < (1<<C); s++) {
    mozne[s] = 0;
    for (int i = 0; i < C; i++) {
      int prazdno = 1;
      for (int j = 0; j < W; j++) if (i+j >= C || GET(s, i+j)) prazdno = 0;
      if (prazdno) mozne[s] = 1;
    }
  }
  return getrec(C, W, 0);
}

int getres(int R, int C, int W) {
  if (W == 1) return R * C;
  return getlast(C, W) + (R-1) * (C/W);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    fprintf(stderr, "tc%d\n", tc);
    int R, C, W;
    scanf("%d%d%d", &R, &C, &W);
    printf("Case #%d: %d\n", tc, getres(R, C, W));
  }
}
