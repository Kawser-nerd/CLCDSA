#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int a, b, c, d, e, f, ans;

  if(scanf("%d %d %d %d", &a, &b, &c, &d) == 1);

  if(a < c) {
    e = c;
  } else {
    e = a;
  }

  if(b > d) {
    f = d;
  } else {
    f = b;
  }

  if(f < e) {
    ans = 0;
  } else{
    ans = f - e;
  }

  printf("%d", ans);

  return 0;
}