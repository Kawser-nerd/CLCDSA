#include<stdio.h>

int main(){
  long a,b;
  scanf("%lld%lld",&a,&b);
  if(a<0&&b>0)printf("%lld\n",b-a-1);
  else printf("%lld\n",b-a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘long int *’ [-Wformat=]
   scanf("%lld%lld",&a,&b);
         ^
./Main.c:5:9: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 3 has type ‘long int *’ [-Wformat=]
./Main.c:6:22: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘long int’ [-Wformat=]
   if(a<0&&b>0)printf("%lld\n",b-a-1);
                      ^
./Main.c:7:15: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘long int’ [-Wformat=]
   else printf("%lld\n",b-a);
               ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&a,&b);
   ^