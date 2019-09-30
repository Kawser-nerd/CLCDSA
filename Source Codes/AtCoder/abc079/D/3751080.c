#include <stdio.h>

int main(void){
  int H, W;
  int c[20][20] = {};
  int A[210][210] = {};
  int mp = 0;
  int i, j, k;

  scanf("%d %d", &H, &W);
  for(i = 0; i < 10; i++){
    for(j = 0; j < 10; j++){
      scanf("%d", &c[i][j]);
    }
  }
  for(i = 1; i <= H; i++){
    for(j = 1; j <= W; j++){
      scanf("%d", &A[i][j]);
    }
  }

  for(i = 0; i < 10; i++){//??????
    for(j = 0; j < 10; j++){//??????
      for(k = 0; k < 10; k++){//?????
        if(c[j][k] > c[j][i] + c[i][k]){
          c[j][k] = c[j][i] + c[i][k];
        }
      }
    }
  }

  for(i = 1; i <= H; i++){
    for(j = 1; j <= W; j++){
      if(A[i][j] != -1){
        mp += c[A[i][j]][1];
      }
    }
  }

  printf("%d\n", mp);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &H, &W);
   ^
./Main.c:13:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &c[i][j]);
       ^
./Main.c:18:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &A[i][j]);
       ^