#include <stdio.h>
#include <stdlib.h>

int main(){
  int N;
  int x[110] = {}, y[110] = {}, h[110] = {};

  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d %d %d", &x[i], &y[i], &h[i]);
  }

  for(int Cx = 0; Cx <= 100; Cx++){
    for(int Cy = 0; Cy <= 100; Cy++){
      int H;
      for(int i = 0; i < N; i++){
        if(h[i] != 0){
          H = h[i] + abs(x[i] - Cx) + abs(y[i] - Cy);
          break;
        }
      }
      int flag = 1;
      for(int i = 0; i < N; i++){
        if(h[i] != 0 && h[i] + abs(x[i] - Cx) + abs(y[i] - Cy) != H){
          flag = 0;
          break;
        }
        if(h[i] == 0 && H - abs(x[i] - Cx) - abs(y[i] - Cy) > 0){
          flag = 0;
          break;
        }
      }
      if(flag == 1){
        printf("%d %d %d\n", Cx, Cy, H);
      }

    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &x[i], &y[i], &h[i]);
     ^