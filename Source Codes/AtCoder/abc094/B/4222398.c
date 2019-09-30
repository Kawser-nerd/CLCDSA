#include<stdio.h>

int main(){
  int N, M, X, count0 = 0, countN = 0, a;
  scanf("%d %d %d", &N, &M, &X);
  for (int i = 0; i < M; i++){
    scanf("%d", &a);
    if(a < X){
      count0++;
    } else if(a > X){
      countN++;
    }
  }
  if(count0 < countN){
    printf("%d\n", count0);
  } else {
    printf("%d\n", countN);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &N, &M, &X);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a);
     ^