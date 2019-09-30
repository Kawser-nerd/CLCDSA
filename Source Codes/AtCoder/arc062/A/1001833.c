#include<stdio.h>

int main(){
  int N,i;
  long long int T,A,TRatio,ARatio,j,k;

  scanf("%d",&N);
  scanf("%lld %lld",&T,&A);
  for(i=1;i<N;++i){
    scanf("%lld %lld",&TRatio,&ARatio);
    j=T/TRatio;
    if(T%TRatio) ++j;
    k=A/ARatio;
    if(A%ARatio) ++k;
    if(j>k){
      T=TRatio*j;A=ARatio*j;
    }
    else{
      T=TRatio*k;A=ARatio*k;
    }
  }
  printf("%lld\n",T+A);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&T,&A);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&TRatio,&ARatio);
     ^