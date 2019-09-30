#include<stdio.h>

int main(){
 int a,b,c;
 scanf("%d %d", &a,&b);
  c=a;
  a=b;
  b=c;
  printf("%d %d",a,b);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &a,&b);
  ^