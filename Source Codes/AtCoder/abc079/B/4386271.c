#include<stdio.h>

long int lucas(long int a,long int b,long int n){
  if(n==-2) return a;
  if(n==-1) return b;
  if(n==0) return a+b;
  else{
    n--;
    lucas(b,a+b,n);
  }
}

int main(void){
  long int ans,n,l_0=2,l_1=1;
  scanf("%ld",&n);
  ans=lucas(l_0,l_1,n-2);
  printf("%ld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&n);
   ^