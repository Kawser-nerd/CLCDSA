#include <stdio.h>
#include <stdlib.h>
int main(void){
int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  if(b-c>=0){printf("delicious");}
  if(b-c<0&&a-abs(b-c)>=0){printf("safe");}
  if(b-c<0&&a-abs(b-c)<0){printf("dangerous");}
  
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a,&b,&c);
   ^