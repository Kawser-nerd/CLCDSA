#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  int n;
  scanf("%d",&n);
  printf("%d\n",n%2?n+1:n-1);
  return 0;
} ./Main.c: In function �main�:
./Main.c:7:3: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^