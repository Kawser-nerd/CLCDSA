#include <stdio.h>

int main(void){
  int n, Next;
  scanf("%d", &n);
  Next = n % 12;
  Next = Next + 1;
  printf("%d", Next);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^