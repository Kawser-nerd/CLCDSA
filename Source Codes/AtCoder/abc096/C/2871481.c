#include <stdio.h>

int main(void) {
  int h, w, i, j, m[52][52], around, count = 0, flag = 0;
  char s[50][51];

  scanf("%d %d", &h, &w);

  for (i = 0; i < 52; i++) {
    for (j = 0; j < 52; j++) {
      m[i][j] = 0;
    }
  }

  for (i = 0; i < h; i++) {
    scanf("%s", s[i]);
  }

  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        m[i+1][j+1] = 1;
      }
    }
  }

  for (i = 1; i < h+1; i++) {
    for (j = 1; j < w+1; j++) {
      around = m[i-1][j] + m[i+1][j] + m[i][j-1] + m[i][j+1];
      if ((m[i][j] == 1) && (around == 0)) {
        count = 1;
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      break;
    }
  }

  if (count == 0) {
    printf("Yes\n");
  }else {
    printf("No\n");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &h, &w);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s[i]);
     ^