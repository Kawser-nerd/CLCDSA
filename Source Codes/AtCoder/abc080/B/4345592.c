#include <stdio.h>
int main(){
  long long int n;
  scanf("%lld",&n);
  int sum=0,tmp=n;
  while(n!=0){
    sum+=n%10;
    n/=10;
  }
  if(tmp%sum==0) printf("Yes");
  else printf("No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^