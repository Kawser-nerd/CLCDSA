#include<stdio.h>

typedef long long int int64;

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  if(k==0){
    printf("%lld\n",(int64)n*n);
    return;
  }
  int64 ans=0;
  for(int b=k+1;b<=n;b++){
    ans+=(int64)(n/b)*(b-k);
    if(n%b>=k){
      ans+=n%b-k+1;
    }
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^