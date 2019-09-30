#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  int a, b, x = 0, ans = 0;

  if(scanf("%d %d", &a, &b) == 1);

  x = b - a;
  while(x) {
    ans += x;
    x--;
  }

  ans = ans - b;

  printf("%d", ans);

  return 0;
}