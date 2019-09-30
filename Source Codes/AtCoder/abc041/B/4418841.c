#include<stdio.h>

int main(void){
  long a,b,c;
  scanf("%ld%ld%ld",&a,&b,&c);
  printf("%ld",a%1000000007*b%1000000007*c%1000000007);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld%ld",&a,&b,&c);
   ^