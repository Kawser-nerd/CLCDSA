#include <stdio.h>
int main(void){
int a,b,c,d;
  int suml,sumr;
  scanf("%d %d %d %d",&a,&b,&c,&d);
  suml=a+b;
  sumr=c+d;
  if(suml==sumr){printf("Balanced\n");}
  if(suml>sumr){printf("Left\n");}
  if(suml<sumr){printf("Right\n");}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&a,&b,&c,&d);
   ^