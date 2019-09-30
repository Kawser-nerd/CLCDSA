#include<stdio.h>
 
int main(){
  int N, K, i, j;
  float r[100], x, c = 0;
  
  scanf("%d %d", &N, &K);
  
  for (i = 0; i < N; i++){
    scanf("%f", &x);
    if(i == 0){
      r[i] = x;
    } else {
      for (j = i - 1; j >= 0; j--){
        if(x < r[j]){
          r[j + 1] = r[j];
          if(j == 0){
            r[j] = x;
          }
        } else{
          r[j + 1] = x;
          break;
        }
      }
    }
  }
  
  for (i = 0; i < K; i++){
    c = (c + r[N - K + i])/2;
  }
  
  printf("%f\n", c);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &K);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%f", &x);
     ^