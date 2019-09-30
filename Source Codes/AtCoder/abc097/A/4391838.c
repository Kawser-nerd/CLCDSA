#include <stdio.h>
#include <stdlib.h>
int main(void){
  int a,b,c,d;
  scanf("%d %d %d %d",&a,&b,&c,&d);
  if((abs(a-b)<=d&&abs(b-c)<=d)||(abs(a-c)<=d)){printf("Yes");}
  else{printf("No");}
return 0;

} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&a,&b,&c,&d);
   ^