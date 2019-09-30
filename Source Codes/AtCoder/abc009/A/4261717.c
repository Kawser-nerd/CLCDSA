#include <stdio.h>
int main(void){
  long long int n,i;
  scanf("%lld",&n);
  for(i=0;2*i<n;i++){
  }
  printf("%lld\n",i);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^