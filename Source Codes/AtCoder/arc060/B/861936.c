#include <stdio.h>
#include <math.h>
 

long long int f(long long int b,long long int n){
 
  long long int ans=0;
  while(n>=b){
    ans+=(n%b);
    n=n/b;
  }
  return ans+n;
}

int main(){
  long long int n,s;
  long long int i,b;
  scanf("%lld %lld",&n,&s);
 
  if(s==n){
    printf("%lld\n",n+1);
    return 0;
  }
 
  for(i=2;i*i<=n;i++){
    if(f(i,n)==s){
      printf("%lld\n",i);
      return 0;
    }
  }
  i=sqrt(n-s);
  while(i>=1){
    if((n-s)%i==0){
      b=(n-s)/i+1;
      if(f(b,n)==s){
	printf("%lld\n",b);
	return 0;
      }
    }
    i--;
  }
 
  printf("-1\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&n,&s);
   ^