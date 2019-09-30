#include <stdio.h>
int main(void){
int a,b,c;
  scanf("%d",&a);
  b=a/100;//100 no kurai
  if(b==a%10){printf("Yes");}
  else{printf("No");}
  
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^