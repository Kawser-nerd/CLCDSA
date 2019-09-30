#include<stdio.h>

int main(){
  long long n;

  scanf("%lld",&n);
  long long m=n;
  int i=1;
  long long j=1;
  while(n>=10){
    n=n/10;
    i++;
    j=j*10;
  }
  if((m+1)%j==0){
    printf("%lld\n",n+9*(i-1));
  }
  else{
    printf("%lld\n",n-1+9*(i-1));
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^