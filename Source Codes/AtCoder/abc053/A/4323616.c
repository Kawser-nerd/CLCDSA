#include <stdio.h>
int main(void){
int a;
  scanf("%d",&a);
  if(a<1200){printf("ABC");}
  else{printf("ARC");}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^