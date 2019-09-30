#include<stdio.h>

int main(){
  long a,b,c;scanf("%ld%ld%ld",&a,&b,&c);
  if(a%2==0||b%2==0||c%2==0){
    puts("0");
  }else {
    long long ans=a*b;
    if(ans>b*c)ans=b*c;
    if(ans>c*a)ans=c*a;
    printf("%lld\n",ans);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   long a,b,c;scanf("%ld%ld%ld",&a,&b,&c);
              ^