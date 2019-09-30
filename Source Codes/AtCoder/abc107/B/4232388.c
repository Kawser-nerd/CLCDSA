#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
  int h, w;
  char x[102][102], ans[102][102], flag;

  if(scanf("%d %d", &h, &w) == 1);

  for(int i = 0; i < h; i++) {
    flag = 1;
    if(scanf("%s", x[i]) == 1);
    for(int j = 0; j < w; j++) {
      if(x[i][j] == '#') {
        flag = 0;
        break;
      }
    }
    if(flag) {
      i--;
      h--;
    }
  }

  //for(int i = 0; i < h; i++) {
  //  printf("%s\n", x[i]);
  //}

  //printf("\n\n\n\n");

  for(int i = 0; i < w; i++) {
    flag = 1;
    for(int j = 0; j < h; j++) {
      if(x[j][i] == '#') {
        flag = 0;
        break;
      }
    }
    if(flag) {
      for(int l = i; l < w; l++) {
        for(int k = 0; k < h; k++) {
          if(l == w - 1) {
            x[k][l] = '\0';
          } else {
            x[k][l] = x[k][l + 1];
          }
        }
      }
      i--;
      w--;
    }
  }

  for(int i = 0; i < h; i++) {
    printf("%s\n", x[i]);
  }

  return 0;
}