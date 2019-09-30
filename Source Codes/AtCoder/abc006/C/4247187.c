#include<stdio.h>

int main(){
  int N, M;
  scanf("%d %d", &N, &M);
  
  for (int i = 0; i <= 100000; i++){
    if(4*N - M - 2*i >= 0 && M + i - 3*N >= 0){
      printf("%d %d %d", i, 4*N - M - 2*i, M + i - 3*N);
      return 0;
    }
  }
  printf("-1 -1 -1\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &M);
   ^