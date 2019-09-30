#include <stdio.h>
#include <stdlib.h>

int main(void){
  int H,W,K;
  scanf("%d%d%d",&H,&W,&K);

  char str[H][W+1];
  int flag[H][W];
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      if(i < K-1 || j < K-1 || H-i < K || W-j < K)
        flag[i][j] = 1;
      else
        flag[i][j] = 0;
    }
  }
  for(int i = 0;i < H;i++) scanf("%s",str[i]);

  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      if(str[i][j] == 'o') continue;
      for(int x = 1-K;x < K;x++){
        for(int y = 1-K;y < K;y++){
          if(0 <= i+x && i+x < H && 0 <= j+y && j+y < W){
            if(abs(x)+abs(y) < K)
            flag[i+x][j+y] = 1;
          }
        }
      }
    }
  }

  int cnt = 0;
  for(int i = K-1;i < H-K+1;i++){
    for(int j = K-1;j < W-K+1;j++){
      if(!flag[i][j]) cnt++;
    }
  }
  
  printf("%d\n",cnt);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&H,&W,&K);
   ^
./Main.c:18:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < H;i++) scanf("%s",str[i]);
                            ^