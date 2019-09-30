#include <stdio.h>
int main(void){
  int a, b, x;
  scanf("%d%d%d", &a, &b, &x);
  printf("%s\n", (a <= x && a + b >= x) ? "YES" : "NO");  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &a, &b, &x);
   ^