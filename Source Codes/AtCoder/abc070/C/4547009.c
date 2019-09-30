#include<stdio.h>

long long gcd(long long a,long long b){
  return b?gcd(b,a%b):a;
}
int main(){
  long long n,t,i;
  scanf("%lld%lld",&n,&t);
  long long ans=t;
  while(--n){
    scanf("%lld",&t);
    ans=(ans/gcd(ans,t))*t;
  }
  printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&n,&t);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&t);
     ^