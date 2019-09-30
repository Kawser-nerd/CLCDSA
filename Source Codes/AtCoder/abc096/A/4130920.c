#include<stdio.h>

int main(void){
  int a,b;
  scanf("%d %d",&a,&b);
  
  if(a<=b){
    printf("%d\n",a);
  }else{
    printf("%d",a-1);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^