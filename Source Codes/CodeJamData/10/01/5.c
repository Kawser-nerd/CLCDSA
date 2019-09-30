/* Just check powers of two */

#include <stdio.h>
#include <math.h>

int on(int n, int k) {
  int power = pow(2, n);
  return ((k+1) % power)==0;
}

int main() {
  int i, t, n, k;

  scanf("%d", &t);
  for (i=1; i<=t; i++) {
    scanf("%d %d", &n, &k);
    printf("Case #%d: %s\n", i, on(n, k)?"ON":"OFF");
  }

  return 0;
}
