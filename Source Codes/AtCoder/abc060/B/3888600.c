#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int a, b, c, ans = 0;

  if(scanf("%d %d %d", &a, &b, &c) == 1);

  for(int i = 0; i < b; i++) {
    if((i * a) % b == c) {
      ans = 1;
      break;
    }
  }

  if(ans) {
    printf("YES");
  } else {
    printf("NO");
  }

  return 0;
}