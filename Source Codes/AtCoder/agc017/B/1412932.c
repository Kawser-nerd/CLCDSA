#include <stdio.h>

int main(void){
  long long int N,A,B,C,D;
  int i,j,k;
  scanf("%lld %lld %lld %lld %lld",&N,&A,&B,&C,&D);
  for(k=0;k<N;k++){
    if(A+C*(N-k-1)-D*k <= B && B <= A+D*(N-k-1)-C*k){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld %lld %lld",&N,&A,&B,&C,&D);
   ^