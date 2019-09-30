#include<stdio.h>
int a, b;
int main(){
  scanf("%d%d", &a, &b);
  printf("%d\n", b+b-a);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^