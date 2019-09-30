#include<stdio.h>
int main(){
  long long s=0,a,b,n,c=1e18;
  scanf("%lld",&n);
  while(n--){
    scanf("%lld %lld",&a,&b);
    s+=a;
    if(a>b&&c>b)c=b;
  }
  if(s<c)c=s;
  printf("%lld\n",s-c);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&a,&b);
     ^