#include <stdio.h>
#define INF 1e18

long long min(long long a,long long b){
  if(a < b){
    return a;
  }
  return b;
}


int main(void){
  int H,W,T;
  scanf("%d%d%d",&H,&W,&T);

  int sx,sy,gx,gy;
  char str[H+1][W+1];
  char s[W+1];
  long long dp[12][12][12][12];
  for(int i = 1;i <= H;i++){
    scanf("%s",s);
    for(int j = 1;j <= W;j++){
      str[i][j] = s[j-1];
      if(str[i][j] == 'S'){
        sx = i;
        sy = j;
      }
      if(str[i][j] == 'G'){
        gx = i;
        gy = j;
      }
    }
  }

  long long left = 0;
  long long right = T+1;
  long long mid = (right+left)/2;
  while(right-left > 1){
    mid = (right+left)/2;
    for(int x = 1;x <= H;x++) for(int y = 1;y <= W;y++){
      for(int px = 1;px <= H;px++) for(int py = 1;py <= W;py++){
        dp[px][py][x][y] = INF;
      }
      long long t = str[x][y]=='#'?mid:1;
      dp[x][y][x][y] = 0;
      dp[x-1][y][x][y] = t;
      dp[x][y-1][x][y] = t;
      dp[x+1][y][x][y] = t;
      dp[x][y+1][x][y] = t;
    }
    for(int kx = 1;kx <= H;kx++) for(int ky = 1;ky <= W;ky++){
      for(int ix = 1;ix <= H;ix++) for(int iy = 1;iy <= W;iy++){
        for(int jx = 1;jx <= H;jx++) for(int jy = 1;jy <= W;jy++){
          dp[ix][iy][jx][jy] = min(dp[ix][iy][jx][jy],dp[ix][iy][kx][ky]+dp[kx][ky][jx][jy]);
        }
      }
    }

    if(dp[sx][sy][gx][gy] <= T){
      left = mid;
    }else{
      right = mid;
    }
  }

  printf("%lld\n",left);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&H,&W,&T);
   ^
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^