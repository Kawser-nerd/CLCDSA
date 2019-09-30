#include <stdio.h>
int main(){
  long long int n,a[99];
  scanf("%lld",&n);
  a[0]=2;a[1]=1;
  for(int i=2;i<=n;i++){
    a[i]=a[i-1]+a[i-2];
  }
  printf("%lld",a[n]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^