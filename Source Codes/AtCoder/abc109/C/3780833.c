#include <stdio.h>
#include <stdlib.h>

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

  int D = abs(x[0] - X);
  for(int i = 1; i < N; i++){
    D = euclid(D, abs(x[i] - X));
  }
  printf("%d\n", D);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &X);
   ^
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &x[i]);
     ^