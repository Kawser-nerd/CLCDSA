#include <stdio.h>
int main(void){
int a;
  int b;
  b=0;
  scanf("%d",&a);
  printf("%d\n",a);
  for(;;){
  printf("1\n");
  b=b+1;
  if(a==b){break;}
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^