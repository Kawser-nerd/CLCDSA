#include <stdio.h>

int main(){
  long long int n,a,b;
  scanf("%lld%lld%lld", &n, &a, &b);
  long long int ans;
  if(n==1){
    if(a==b){
      ans = 1;
    }else{
      ans = 0;
    }
  }else{
    if(a>b){
      ans = 0;
    }else if(a==b){
      ans = 1;
    }else{
      ans = (n-2) * (b-a) + 1;
    }
  }
  printf("%lld\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &n, &a, &b);
   ^