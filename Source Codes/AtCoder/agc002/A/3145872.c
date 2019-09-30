#include <stdio.h>
int main(void){
 int a,b;
 scanf("%d%d",&a,&b);
 if(a<=0&&b>=0) puts("Zero");
 else if(a>0 || (b-a)%2==1) puts("Positive");
 else puts("Negative");
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^