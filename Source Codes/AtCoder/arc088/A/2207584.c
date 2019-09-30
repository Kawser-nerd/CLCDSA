#include<stdio.h>
#include<math.h>

int main(){
  long long x,y;
  scanf("%lld%lld",&x,&y);
  long long ans=0;
  while(y>=x){
    x=x*2;
    ans++;
  }
  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&x,&y);
   ^