#include <stdio.h>
int main(void){
 long long int a,b,c,m;
 scanf("%lld%lld%lld",&a,&b,&c);
 m=a;
 if(m<b) m=b;
 if(m<c) m=c;
 if(m%2==0) puts("0");
 else printf("%lld",m==a?b*c:m==b?a*c:a*b);
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&a,&b,&c);
  ^