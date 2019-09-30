#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int h, w, ans = 1;
  char s[51][51];

  if(scanf("%d %d", &h, &w) == 1);

  for(int i = 0; i < h; i++) {
    if(scanf("%s", s[i]) == 1);
  }

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(s[i][j] == '#') {
        ans--;
        if(s[i+1][j] == '#' || s[i-1][j] == '#' || s[i][j+1] == '#' || s[i][j-1] == '#') {
          ans++;
        }
      }
    }
  }

  if(ans == 1) {
    printf("Yes");
  } else {
    printf("No");
  }

  return 0;
}