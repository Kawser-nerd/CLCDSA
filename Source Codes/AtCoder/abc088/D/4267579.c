#include <stdio.h>
#define INF 1 << 30

int H,W;
int white = 0;
int visited[50][50];

int vx[4] = {0,1,0,-1};
int vy[4] = {1,0,-1,0};

int que[3000];
int top = 0;
int bottom = 0;

void push(int x){
  que[bottom] = x;
  bottom++;
}

int pop(){
  if(top >= bottom) return -1;
  return que[top++];
}

int main(void){
  scanf("%d%d",&H,&W);

  char str[W];
  for(int i = 0;i < H;i++){
    scanf("%s",str);
    for(int j = 0;j < W;j++){
      if(str[j] == '#'){
        visited[i][j] = -1;
      }else{
        visited[i][j] = 0;
        white++;
      }
    }
  }
  push(0);
  visited[0][0] = 1;

  while(1){
    int p = pop();
    if(p == -1) break;

    int x = p/1000;
    int y = p%1000;

    for(int i = 0;i < 4;i++){
      int xx = x+vx[i];
      int yy = y+vy[i];
      if(0 <= xx && xx < H && 0 <= yy && yy < W){
        if(visited[xx][yy] == 0){
          push(xx*1000+yy);
          visited[xx][yy] = visited[x][y]+1;
        }
      }
    }
  }

  if(!visited[H-1][W-1]) printf("-1\n");
  else printf("%d\n",white-visited[H-1][W-1]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&H,&W);
   ^
./Main.c:30:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",str);
     ^