#include<stdio.h>

int main(){
  int N, K, x, i, d;
  
  scanf("%d", &N);
  scanf("%d", &K);
  
  for (i = 0; i < N; i++){
    scanf("%d", &x);
    if(x <= K/2){
      d += x;
    } else {
      d += K - x;
    }
  }
  
  printf("%d\n", 2*d);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &K);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &x);
     ^