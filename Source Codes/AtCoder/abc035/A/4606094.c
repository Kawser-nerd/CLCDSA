#include <stdio.h>
int main(void){
int a,b;
  scanf("%d %d",&a,&b);
  if(a%16==b%9){printf("16:9\n");}
  else{printf("4:3\n");}
  
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^