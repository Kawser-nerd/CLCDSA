#include <stdio.h>
int main(void){
int a,b;
  scanf("%d %d",&a,&b);
if((a+b)%2==0){printf("%d",(a+b)/2);}
  else{printf("%d",(a+b)/2+1);}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^