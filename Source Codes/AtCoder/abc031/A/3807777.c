#include <stdio.h>

int main(){
  int a, d, x, y;

  scanf("%d %d", &a, &d);

  x = (a + 1) * d;
  y = a * (d + 1);

  if (x >= y) {
    printf("%d\n", x);
  }
  else {
    printf("%d\n", y);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &a, &d);
   ^