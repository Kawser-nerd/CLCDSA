#include <stdio.h>

int main(void) {
  int a, b, c, i, N;
  for (i = 0, scanf("%d%d",&N,&a); i < N && scanf("%d",&b); i++) {
    while (b) {
      c = b;
      b = a%b;
      a = c;
    }
  }
  printf("%d",a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for (i = 0, scanf("%d%d",&N,&a); i < N && scanf("%d",&b); i++) {
               ^