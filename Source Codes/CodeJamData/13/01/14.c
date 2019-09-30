#include <stdio.h>

char map[9][9];

int check() {
  int r, c, o, x;
  for (r = 0; r < 4; r++) {
    o = 0, x = 0;
    for (c = 0; c < 4; c++)
      if (map[r][c] == 'X') x++;
      else if (map[r][c] == 'O') o++;
      else if (map[r][c] == 'T') x++, o++;
    if (o == 4) return 0;
    if (x == 4) return 1;
  }
  for (c = 0; c < 4; c++) {
    o = 0, x = 0;
    for (r = 0; r < 4; r++)
      if (map[r][c] == 'X') x++;
      else if (map[r][c] == 'O') o++;
      else if (map[r][c] == 'T') x++, o++;
    if (o == 4) return 0;
    if (x == 4) return 1;
  }
  o = 0, x = 0;
  for (r = 0, c = 0; r < 4 && c < 4; r++, c++) {
    if (map[r][c] == 'X') x++;
    else if (map[r][c] == 'O') o++;
    else if (map[r][c] == 'T') x++, o++;
    if (o == 4) return 0;
    if (x == 4) return 1;
  }
  o = 0, x = 0;
  for (r = 0, c = 3; r < 4 && c >= 0; r++, c--) {
    if (map[r][c] == 'X') x++;
    else if (map[r][c] == 'O') o++;
    else if (map[r][c] == 'T') x++, o++;
    if (o == 4) return 0;
    if (x == 4) return 1;
  }
  int cnt = 0;
  for (r = 0; r < 4; r++)
    for (c = 0; c < 4; c++)
      if (map[r][c] != '.') cnt++;
  if (cnt == 16) return 2;
  return 3;
}

int main() {
  int C = 1, T;
  scanf("%d", &T);
  while (T--) {
    int r, c;
    for (r = 0; r < 4; r++)
      scanf("%s", map[r]);
    printf("Case #%d: ", C++);
    int result = check();
    if (result == 0) puts("O won");
    else if (result == 1) puts("X won");
    else if (result == 2) puts("Draw");
    else puts("Game has not completed");
  }
  return 0;
}
