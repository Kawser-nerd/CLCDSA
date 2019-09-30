#include <stdio.h>

long long absu(long long  a){
  if(a > 0){
    return a;
  }
  return -a;
}

long long gcd(long long a,long long b){
  if(b > 0){
    gcd(b,a%b);
  }else{
    return a;
  }
}

int main(void){
  long N;
  long long X,data;
  scanf("%ld%lld",&N,&X);
  long long x[N];

  for(int i = 0;i < N;i++){
    scanf("%lld",&data);
    x[i] = absu(X-data);
  }

  long long ans = x[0];
  for(int i = 1;i < N;i++){
    ans = gcd(x[i],ans);
  }

  printf("%lld",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%lld",&N,&X);
   ^
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&data);
     ^