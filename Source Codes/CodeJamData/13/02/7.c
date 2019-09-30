#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 112

int lawn[MAXN][MAXN];
int rows[MAXN][MAXN];
int cols[MAXN][MAXN];
int N, M;

int main() {
  int T, tc;

  scanf("%d", &T);
  for (tc = 0; tc < T; ++tc) {
    int i, j, x, res = 1;

    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));

    scanf("%d%d", &N, &M);
    for (i = 0; i < N; ++i)
      for (j = 0; j < M; ++j) {
        scanf("%d", &x); 

        lawn[i][j] = x;
        ++rows[i][x];
        ++cols[j][x];
      }

    for (i = 0; i < N; ++i) for (x = MAXN-2; x >= 0; --x) rows[i][x] += rows[i][x+1];
    for (i = 0; i < M; ++i) for (x = MAXN-2; x >= 0; --x) cols[i][x] += cols[i][x+1];

    for (i = 0; i < N; ++i)
      for (j = 0; j < M; ++j) {
        x = lawn[i][j];
        if (rows[i][x+1] && cols[j][x+1]) {
          res = 0;
          goto out;
        }
      }

  out:
    printf("Case #%d: %s\n", tc+1, res ? "YES" : "NO");
  }

  return EXIT_SUCCESS;
}
