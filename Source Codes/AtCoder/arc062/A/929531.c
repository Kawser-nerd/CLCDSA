#include<stdio.h>
int main(){
  long long n,a,b,x,y;
  scanf("%lld %lld %lld",&n,&x,&y);
  while(--n){
    scanf("%lld %lld",&a,&b);
    if(x/a>y/b){
      if(x%a)x=x-x%a+a;
      y=x/a*b;//printf("%lld %lld\n",x,y);
    }
    else{
      if(y%b)y=y-y%b+b;
      x=y/b*a;
    }
  }
  printf("%lld\n",x+y); 
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld",&n,&x,&y);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&a,&b);
     ^