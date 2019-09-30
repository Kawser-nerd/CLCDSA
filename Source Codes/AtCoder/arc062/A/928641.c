#include<stdio.h>

#define MAX(x,y) (((x)>(y))?(x):(y))

int main(void){
  long long nowT,nowA,N,T,A;
  long long coef;

  scanf("%d",&N);
  scanf("%lld%lld",&nowT,&nowA);
  while(--N){
    scanf("%lld%lld",&T,&A);
    if(nowT%T!=0) nowT+=T-nowT%T;
    if(nowA%A!=0) nowA+=A-nowA%A;
    coef=MAX(nowT/T,nowA/A);
    nowT=T*coef;
    nowA=A*coef;
  }
  printf("%lld\n",nowT+nowA);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:9: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
   scanf("%d",&N);
         ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&nowT,&nowA);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&T,&A);
     ^