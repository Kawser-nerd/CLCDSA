#include <stdio.h>
#include <stdlib.h>
#define int long long

signed compare_int(const void *a,const void *b){
  return *(int*)a-*(int*)b;
}

int main(void){
  int N,M;
  scanf("%lld%lld",&N,&M);

  int A[N+1];
  int B[N+1];
  for(int i = 1;i <= N;i++) scanf("%lld",&A[i]);

  A[0] = 0;
  for(int i = 1;i <= N;i++){
    A[i] = (A[i]+A[i-1])%M;
  }

  qsort(A,N+1,sizeof(int),compare_int);

  long long ans = 0;
  int j = 0;
  B[0] = 1;
  for(int i = 1;i <= N;i++){
    if(A[i] == A[i-1]) B[j]++;
    else B[++j] = 1;
  }

  for(int i = 0;i <= j;i++){
    ans += (B[i]*(B[i]-1))/2;
  }

  printf("%lld\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&N,&M);
   ^
./Main.c:15:29: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 1;i <= N;i++) scanf("%lld",&A[i]);
                             ^