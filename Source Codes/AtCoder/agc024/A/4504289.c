#include<stdio.h>
int main(){
  long long a,b,c,d;
  scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
  a-=b;
  printf("%d",a-2*a*(d%2));
} ./Main.c: In function ‘main’:
./Main.c:6:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
   printf("%d",a-2*a*(d%2));
          ^
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
   ^