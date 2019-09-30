#include <stdio.h>
#include <string.h>

long int gcd(long int a, long int b) {
  if (b == 0){
    return a;
  }
  return gcd(b, a % b);
}

long int lcm(long int a, long int b) {
  return a*b/ gcd(a, b);
}



int main(){
  long int N,M;
  scanf("%ld%ld",&N,&M);
  char S[100000];
  char T[100000];
  scanf("%s",S);
  scanf("%s",T);
  int i;
  int flag=0;
  long int ans=-1;
  for(i=0;i<N;i++){
    if((i*M)%N==0 && S[i]!=T[i*M/N]){
	flag=1;
    }
  }
  if(flag==0){
    ans=lcm(N,M);
  }
  printf("%ld",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld",&N,&M);
   ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",T);
   ^