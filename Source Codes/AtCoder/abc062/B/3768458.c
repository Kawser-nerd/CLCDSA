#include <stdio.h>

int main(){
  int H, W;
  char a[110][110] = {};
  char b[110][110] = {};

  scanf("%d%d", &H, &W);
  for(int i = 0; i < H; i++){
    scanf("%s", a[i]);
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      b[i+1][j+1] = a[i][j];
    }
  }

  for(int i = 0; i < H + 2; i++){
    b[i][0]   = '#';
    b[i][W+1] = '#';
  }

  for(int j = 0; j < W + 2; j++){
    b[0][j]   = '#';
    b[H+1][j] = '#';
  }

  for(int i = 0; i < H + 2; i++){
    printf("%s\n", b[i]);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &H, &W);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", a[i]);
     ^