#include <stdio.h>
#include <math.h>
int main(void){
  long long int a,b,i;
  scanf("%lld %lld",&a,&b);
  if(a>0&&a<=b) printf("Positive");
  else if(a<=0&&0<=b) printf("Zero");
  else if(a<=b&&b<0){
    if((b-a+1)%2==0) printf("Positive");
    else printf("Negative");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&a,&b);
   ^