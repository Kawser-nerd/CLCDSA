#include <stdio.h>
#define mod 1000000007

int H,W;

long data[1000][1000];
long dp[1000][1000];

int vx[4] = {0,1,0,-1};
int vy[4] = {1,0,-1,0};

void init(int H,int W){
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      dp[i][j] = 0;
    }
  }
}

long dfs(int x, int y){
  int ret = 1;
  if(dp[x][y]){
    return dp[x][y];
  }

  for(int i = 0;i < 4;i++){
    int xx = x+vx[i];
    int yy = y+vy[i];

    if(0 <= xx && xx < H && 0 <= yy && yy < W){
      if(data[x][y] < data[xx][yy]){
        ret += dfs(xx,yy);
        ret %= mod;
      }
    }
  }

  dp[x][y] = ret%mod;
  return dp[x][y];
}


int main(void){
  scanf("%d%d",&H,&W);
  init(H,W);

  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      scanf("%ld",&data[i][j]);
    }
  }

  long long ans = 0;
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      ans += dfs(i,j);
      ans %= mod;
    }
  }

  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:44:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&H,&W);
   ^
./Main.c:49:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%ld",&data[i][j]);
       ^