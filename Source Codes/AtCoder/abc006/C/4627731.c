#include <stdio.h>

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  int i,j,k;

  k = 0;
  i = (4*N-M)/2;
  j = (M-2*N)/2;

  if(i+j+k == N && i*2+j*4 == M && i >= 0 && j >= 0){
    printf("%d %d %d\n",i,k,j);
    return 0;
  }

  N--;
  M -= 3;
  k = 1;
  i = (4*N-M)/2;
  j = (M-2*N)/2;

  if(i+j+k == N+1 && i*2+j*4 == M && i >= 0 && j >= 0){
    printf("%d %d %d\n",i,k,j);
    return 0;
  }

  printf("-1 -1 -1\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^