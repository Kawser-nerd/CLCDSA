#include <stdio.h>

int main(void){
  int a,b,x,num=0;
  scanf("%d",&x );
  int i=1;
  while(1){
    num=num+i;
    if(num>=x){
      break;
    }
    i++;
  }
  printf("%d\n",i );

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x );
   ^