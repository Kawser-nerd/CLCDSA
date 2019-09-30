#include <stdio.h>
int main(){
  int a,b,c,d,e,f;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  e=c-a;//|
  f=d-b;//-
  printf("%d %d %d %d",c-f,d+e,a-f,b+e);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&a,&b,&c,&d);
   ^