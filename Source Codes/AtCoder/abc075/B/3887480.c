#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int h, w, ans = 0;
  char s[51][51];

  if(scanf("%d %d", &h, &w) == 1);

  for(int i = 0; i < h; i++) {
    if(scanf("%s", s[i]) == 1);
  }

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(s[i][j] == '.') {
        for(int k = i - 1; k <= i + 1 && k < h; k++) {
          if(k < 0) {
            continue;
          }
          for(int l = j - 1; l <= j + 1 && l < w; l++) {
            if(l < 0) {
              continue;
            }
            if(s[k][l] == '#') {
              ans++;
            }
          }
        }
        s[i][j] = ans + '0';
        ans = 0;
      }
    }
    printf("%s\n", s[i]);
  }

  return 0;
}