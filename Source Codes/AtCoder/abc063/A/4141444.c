#include <stdio.h>

int main(void){
  int a, b, c;
  scanf("%d %d", &a, &b);
  c = a + b;
  if(c <= 9) printf("%d\n", c);
  else printf("error\n");
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &a, &b);
   ^