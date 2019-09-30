#include <stdio.h>

int main(void){
  int a, b;
  int result;
  
  scanf("%d", &a);
  scanf("%d", &b);
  
  result=a-b;
  printf("%d\n", result);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &b);
   ^