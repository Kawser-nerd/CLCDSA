#include <stdio.h>

int main() {
  int T, t, i, x, y;
  char fd, bk;

  scanf("%d", &T);

  for(t = 1; t <= T; t++) {
    scanf("%d%d", &x, &y);
    printf("Case #%d: ", t);
    if(x < 0) {
      x = -x;
      fd = 'W';
      bk = 'E';
    } else {
      fd = 'E';
      bk = 'W';
    }
    for(i = 0; i < x; i++) {
      printf("%c%c", bk, fd);
    }
    if(y < 0) {
      y = -y;
      fd = 'S';
      bk = 'N';
    } else {
      fd = 'N';
      bk = 'S';
    }
    for(i = 0; i < y; i++) {
      printf("%c%c", bk, fd);
    }
    printf("\n");
  }

  return 0;
}