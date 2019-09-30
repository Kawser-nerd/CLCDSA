#include <stdio.h>
int main(void){
  long long int n;
  scanf("%lld",&n);
  if(n==12){
    printf("%lld\n",n+1-12);
  }
  else{
    printf("%lld\n",n+1);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^