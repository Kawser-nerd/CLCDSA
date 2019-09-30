#include<stdio.h>
int a, b, c;
int main(){
  scanf("%d%d%d", &a, &b, &c);
  printf("%d\n", ((b+c)*a+b*c)<<1);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &a, &b, &c);
   ^