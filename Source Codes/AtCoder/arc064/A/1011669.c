#include<stdio.h>
int main(){
  long long n,m,i,a,b,s=0,c;
  scanf("%lld %lld",&n,&m);
  scanf("%lld",&a);
  if(a>m){
    s+=a-m;
    a=m;
  }
  while(--n){//printf("%d\n",s);
    scanf("%lld",&b);
    c=0;
    if(a+b>m)c=a+b-m;
    s+=c;
    a=b-c;
  }
  printf("%lld\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&n,&m);
   ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&b);
     ^