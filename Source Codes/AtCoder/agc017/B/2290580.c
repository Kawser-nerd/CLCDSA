#include<stdio.h>
#include<stdlib.h>
int main(){
  long long  n,a,b,c,d,i;
  scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);
  b=labs(b-a);
  n--;
  for(i=0;i<n;i++){
    if(d*(n-i)-i*c>=b&&b>=c*(n-i)-i*d)break;
  }
  printf("%s\n",i-n?"YES":"NO");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);
   ^