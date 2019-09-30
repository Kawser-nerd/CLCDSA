#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  long data[8][1000];
  long ans = 0;
  int N, M;
  long tempx, tempy, tempz;
  long temp;
  scanf("%d%d", &N, &M);

  for (int i = 0; i < N; i++) {
    scanf("%ld%ld%ld", &tempx, &tempy, &tempz);
    data[0][i] = tempx + tempy + tempz;
    data[1][i] = tempx + tempy - tempz;
    data[2][i] = tempx - tempy + tempz;
    data[3][i] = tempx - tempy - tempz;
    data[4][i] = -tempx + tempy + tempz;
    data[5][i] = -tempx + tempy - tempz;
    data[6][i] = -tempx - tempy + tempz;
    data[7][i] = -tempx - tempy - tempz;
  }

  for (int loopcount = 0; loopcount < 8; loopcount++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; i + j < N - 1; j++) {
        if (data[loopcount][j] > data[loopcount][j + 1]) {
          temp = data[loopcount][j + 1];
          data[loopcount][j + 1] = data[loopcount][j];
          data[loopcount][j] = temp;
        }
      }
    }
    temp = 0;
    for (int i = 0; i < M; i++) {
      temp += data[loopcount][N - i - 1];
    }
    // for (int debug = 0; debug < N; debug++) {
    //   printf("%d ", data[loopcount][debug]);
    // }
    // printf("\n");
    if (ans < temp) ans = temp;
  }
  printf("%ld", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &N, &M);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld%ld", &tempx, &tempy, &tempz);
     ^