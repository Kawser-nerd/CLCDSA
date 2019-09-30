#include<stdio.h>

int main(void){
   int n,a=0;
   scanf("%d",&n);
   for(int i=0;i<10;i++){
      if((1<<i) <= n)a=(1<<i);
   }
   printf("%d",a);
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&n);
    ^