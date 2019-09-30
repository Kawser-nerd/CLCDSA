#include<stdio.h>

int main(){
  int N, i, j, sum = 0, pr;
  
  for (i = 1; i <= 9; i++){
    for (j = 1; j <= 9; j++){
      sum += i*j;
    }
  }
  
  scanf("%d", &N);
  
  pr = sum - N;
  for (i = 1; i <= 9; i++){
    for (j = 1; j <= 9; j++){
      if(i*j == pr){
        printf("%d x %d\n", i, j);
      }
    }
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^