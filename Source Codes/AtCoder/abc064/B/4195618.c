#include<stdio.h>

int main(){
  int N, a, max = 0, min = 1001, i;
  
  scanf("%d", &N);
  
  for (i = 0; i < N; i++){
    scanf("%d", &a);
    if(a > max){
      max = a;
    }
    if(a < min){
      min = a;
    }
  }
  
  printf("%d\n", max - min);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a);
     ^