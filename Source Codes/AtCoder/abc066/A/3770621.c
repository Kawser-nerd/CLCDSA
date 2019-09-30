#include<stdio.h>
int a, b, c, ans, max;
int main(){
  scanf("%d%d%d", &a, &b, &c);
  max=a;
  if(b>max){max=b;}
  if(c>max){max=c;}
  printf("%d\n", a+b+c-max);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &a, &b, &c);
   ^