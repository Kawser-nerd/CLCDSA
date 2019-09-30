#include <stdio.h>

int R, C, map[199][199];

int chk() {
  int r, c;
  for (r = 0; r < R; r++)
    for (c = 0; c < C; c++) {
      int r1, c1, cOk = 1, rOk = 1;
      for (c1 = 0; c1 < C; c1++)
        if (map[r][c1] > map[r][c]) cOk = 0;
      for (r1 = 0; r1 < R; r1++)
        if (map[r1][c] > map[r][c]) rOk = 0;
      if (!rOk && !cOk) return 0;
    }
  return 1;
}
/*
int chk() {
  int r, c, max[199][199];
  for (r = 0; r < R; r++)
    for (c = 0; c < C; c++)
      max[r][c] = map[r][c];
  for (r = 0; r < R; r++) {
    int min = 999, pos = -1;
    for (c = 0; c < C; c++)
      if (map[r][c] < min) min = map[r][c], pos = c;
    int r1, c1, rOk = 1, cOk = 1;
    for (c1 = 0; c1 < C && rOk; c1++)
      if (map[r][c1] != min) rOk = 0;
    for (r1 = 0; r1 < R && cOk; r1++)
      if (map[r1][pos] != min) cOk = 0;
    if (!rOk && !cOk) return 0;
    if (rOk) {
      for (c1 = 0; c1 < C && rOk; c1++)
        max[r][c1] = min < max[r][c1] ? min : max[r][c1];
    }
    if (cOk) {
      for (r1 = 0; r1 < R && rOk; r1++)
        max[r1][pos] = min < max[r1][pos] ? min : max[r1][pos];
    }
  }
  for (r = 0; r < R; r++)
    for (c = 0; c < C; c++) {
      if (map[r][c] > max[r][c]) return 0;
    }
  return 1;
}
*/

int main() {
  int Case = 1, T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &R, &C);
    int r, c;
    for (r = 0; r < R; r++)
      for (c = 0; c < C; c++)
        scanf("%d", &map[r][c]);
    printf("Case #%d: ", Case++);
    /*
    puts("");
    for (r = 0; r < R; r++)
      for (c = 0; c < C; c++)
        printf("%d%s", map[r][c], c == C - 1 ? "\n" : " ");
    */
    int result = chk();
    if (!result) puts("NO");
    else puts("YES");
  }
  return 0;
}
