#include <stdio.h>
int main(void){
int a,b;
scanf("%d %d",&a,&b);
  if(a>b){printf("%d",a-1);}
  else{printf("%d",a);}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d %d",&a,&b);
 ^