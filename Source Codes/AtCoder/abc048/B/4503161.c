#include<stdio.h>
#include<math.h>

int main(void){
  long long int i,a,b,x,ans;
  scanf("%lld %lld %lld",&a,&b,&x);
  ans=b/x-a/x;
  if(a%x==0)ans++;
  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld",&a,&b,&x);
   ^