#include <stdio.h>

int main() {
  int r,g;
  
  scanf("%d %d", &r, &g);
  
  printf("%d\n",2*g-r);
  return 0;
} ./Main.c: In function �main�:
./Main.c:6:3: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &r, &g);
   ^