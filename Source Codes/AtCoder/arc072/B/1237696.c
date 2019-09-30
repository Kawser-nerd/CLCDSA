#include<stdio.h>
int main(){
  long long a,b;
  scanf("%lld %lld",&a,&b);
  printf("%s\n",a-b<-1||1<a-b?"Alice":"Brown");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&a,&b);
   ^