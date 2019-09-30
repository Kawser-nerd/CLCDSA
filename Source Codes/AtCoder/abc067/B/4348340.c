#include<stdio.h>

int main(){
  int i,j,k,N,K;
  
  scanf("%d %d",&N,&K);
  int A[N];
  for(i=0;i<N;i++)
    scanf("%d ",&A[i]);
  int tmp;
   for (i=0; i<N; ++i) {
    for (j=i+1; j<N; ++j) {
      if (A[i] < A[j]) {
        tmp =  A[i];
        A[i] = A[j];
        A[j] = tmp;
      }
    }
  }

  k=0;
  for(i=0;i<K;i++)
    k+=A[i];
  
  printf("%d\n",k);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&K);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d ",&A[i]);
     ^