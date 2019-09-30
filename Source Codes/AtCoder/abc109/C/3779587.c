#include <stdio.h>
#include <stdlib.h>

int compare_int_ao(const void *a, const void *b){
  return *(int *)a - *(int *)b;
}

int euclid(int a, int b){
  if(a < b){
    int tmp = a;
    a = b;
    b = tmp;
  }
  int r = a % b;
  if(r < 0){
    r += b;
  }
  while(r != 0){
    a = b;
    b = r;
    r = a % b;
    if(r < 0){
      r += b;
    }
  }
  return b;
}

int main(){
  int N, X;
  int x[100010] = {};

  scanf("%d %d", &N, &X);
  for(int i = 0; i < N; i++){
    scanf("%d", &x[i]);
  }
  x[N] = X;
  qsort(x, N + 1, sizeof(int), compare_int_ao);

  if(N == 1){
    printf("%d\n", x[1] - x[0]);
  }else{
    int D = euclid(x[2] - x[1], x[1] - x[0]);
    for(int i = 2; i < N; i++){
      D = euclid(D, x[i+1] - x[i]);
    }
    printf("%d\n", D);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &X);
   ^
./Main.c:35:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &x[i]);
     ^