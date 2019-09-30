#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
  long long int a,b,c,div;
  scanf("%lld%lld%lld",&a,&b,&c);
  if((a*b*c)%2==0) div=0;
  else{
    div=a*b;
    if(div>b*c) div=b*c;
    if(div>a*c) div=a*c;
  }
  printf("%lld",div);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&a,&b,&c);
   ^