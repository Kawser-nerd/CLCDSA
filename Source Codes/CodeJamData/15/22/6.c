#define DEBUG 1

#include "../../stdc++.h"
using namespace std;

#define MAXRC 16

int dp[5][17][17], R, C;
bool g[4][16];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void f(int r, int c, int n) {
  if(c == C) {
    //count
    int unhappy = 0;
    for(r = 0; r < R; r++)
      for(c = 0; c < C; c++)
	if(g[r][c])
	  for(int d = 0; d < 4; d++) {
	    int nr = r + dr[d];
	    int nc = c + dc[d];
	    if(nr >= 0 && nr < R && nc >= 0 && nc < C && g[nr][nc])
	      unhappy++;
	  }
    dp[R][C][n] = min(dp[R][C][n], unhappy / 2);
    return;
  }
  g[r][c] = true;
  f((r + 1) % R, c + (r + 1 == R), n + 1);
  g[r][c] = false;
  f((r + 1) % R, c + (r + 1 == R), n);
}

int main() {
  int cn, tc, N;
  for(R = 1; R <= 4; R++)
    for(C = R; R * C <= 16; C++) {
      for(N = 0; N <= R * C; N++)
	dp[R][C][N] = INT_MAX;
      f(0, 0, 0);
    }
  scanf("%d", &tc);
  for(cn = 1; cn <= tc; cn++) {
    scanf("%d%d%d", &R, &C, &N);
    printf("Case #%d: %d\n", cn, dp[min(R, C)][max(R, C)][N]);
  }
  return 0;
}
