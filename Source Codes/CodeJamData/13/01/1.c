#include <stdio.h>

int main ()
{
  int i, t, j, k, b[16], p;
  scanf ("%d", &t);
  for (i = 1; i <= t; i++) {
    for (j = 0; j < 16; ) {
      if (((b[j] = getchar ()) >= 'O' && b[j] <= 'X') || b[j] == '.') j++;
    }
    for (p = 'O'; p <= 'X'; p += 'X' - 'O') {
      for (j = 0; j < 16; j += 4) {
        for (k = j / 4; k < 16 && (b[k] == p || b[k] == 'T'); k += 4) {}
        if (k >= 16) break;
        for (k = j; k < j + 4 && (b[k] == p || b[k] == 'T'); k++) {}
        if (k >= j + 4) break;
      }
      if (j < 16) break;
      for (k = 0; k < 16 && (b[k] == p || b[k] == 'T'); k += 5) {}
      if (k >= 16) break;
      for (k = 3; k < 3 + 3*4 && (b[k] == p || b[k] == 'T'); k += 3) {}
      if (k >= 3 + 3 * 4) break;
    }
    if (p == 'O' || p == 'X') printf ("Case #%d: %c won\n", i, p);
    else {
      for (j = 0; j < 16 && b[j] != '.'; j++) {}
      printf ("Case #%d: %s\n", i, j < 16 ? "Game has not completed" : "Draw");
    }
  }
  return 0;
}
