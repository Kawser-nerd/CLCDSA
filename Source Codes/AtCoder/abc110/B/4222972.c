#include<stdio.h>

int main(){
  int N, M, X, Y, x, y, max = -100, min = 100, flag = 0;
  
  scanf("%d %d %d %d", &N, &M, &X, &Y);
  for (int i = 0; i < N; i++){
    scanf("%d", &x);
    if(max < x){
      max = x;
    }
  }
  for (int i = 0; i < M; i++){
    scanf("%d", &y);
    if(min > y){
      min = y;
    }
  }
  for (int i = max + 1; i <= min; i++){
    if(i > X && i <= Y){
      flag = 1;
      break;
    }
  }
  
  if(flag == 1){
    printf("No War\n");
  } else {
    printf("War\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d", &N, &M, &X, &Y);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &x);
     ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &y);
     ^