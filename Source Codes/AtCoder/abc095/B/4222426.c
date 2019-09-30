#include<stdio.h>

int main(){
  int N, X, m, min = 100001, count;
  
  scanf("%d %d", &N, &X);
  for (int i = 0; i < N; i++){
    scanf("%d", &m);
    if(min > m){
      min = m;
    }
    X -= m;
  }
  
  count = N + X/min;
  printf("%d\n", count);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &X);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &m);
     ^