#include<stdio.h>
#include<math.h>

int main(){
  long long q,h,s,d;
  scanf("%lld%lld%lld%lld",&q,&h,&s,&d);
  long long n;
  scanf("%lld",&n);
  long long min1=0;
  if(4*q<=2*h&&4*q<=s){
    min1=4*q;
  }
  else if(2*h<=4*q&&2*h<=s){
    min1=2*h;
  }
  else{
    min1=s;
  }

  if(n%2==0){
    if(2*min1<=d){
      printf("%lld\n",n*min1);
    }
    else{
      printf("%lld\n",d*n/2);
    }
  }
  else{
    if(2*min1<=d){
      printf("%lld\n",min1*n);
    }
    else{
      printf("%lld\n",min1+d*(n-1)/2);
    }
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld",&q,&h,&s,&d);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^