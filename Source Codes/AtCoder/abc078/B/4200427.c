#include<stdio.h>

int main(){
  int X, Y, Z;
  
  scanf("%d %d %d", &X, &Y, &Z);
  
  printf("%d\n", (X - Z)/(Y + Z));
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &X, &Y, &Z);
   ^