#include<stdio.h>
int main(){
  long long n,a,b=0,s=0;
  scanf("%lld",&n);
  while(n--){
    scanf("%lld",&a);
    b+=a;
    s+=b/2;
    b=a?b%2:0;
  }
  printf("%lld\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&a);
     ^