#include<stdio.h>

int main(void){
  int i,a,b;
  scanf("%d%d",&a,&b);
  for(i=0;;i++){
    if(i*a>=b) break;
  }
  printf("%d\n",i);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^