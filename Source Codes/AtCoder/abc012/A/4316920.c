#include <stdio.h>
int main(void){
int a,b,c;
  scanf("%d %d",&a,&b);
  c=a;
  a=b;
  b=c;
  printf("%d %d\n",a,b);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^