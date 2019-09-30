#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
  int n, c = 0, flag = 1;
  char w[102][12], kari[2];

  if(scanf("%d", &n) != 0);

  for(int i = 0; i < n; i++) {
    if(scanf("%s", w[i]) != 0);
  }

  for(int i = 0; i < n - 1 && flag; i++) {
    for(int j = i + 1; j < n; j++) {
      if(strcmp(w[i], w[j]) == 0) {
        printf("No");
        flag = 0;
        break;
      }
    }
  }

  kari[0] = w[0][strlen(w[0]) - 1];

  for(int i = 1; i < n && flag; i++) {
    if(kari[0] == w[i][0]) {
      c++;
    } else {
      printf("No");
      break;
    }

    if(c == n - 1) {
      printf("Yes");
    }
    kari[0] = w[i][strlen(w[i]) - 1];
  }

  return 0;
}