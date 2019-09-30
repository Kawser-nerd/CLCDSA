#include <stdio.h>
#define limit 100000

int top = 0;
int bottom = 0;

int que[limit];

void push(int x){
  que[bottom++] = x;
}

int pop(){
  if(bottom <= top) return -1;
  return que[top++];
}

int vx[4] = {0,0,1,-1};
int vy[4] = {1,-1,0,0};

int main(void){
  int R,C;
  int sx,sy,gx,gy;
  scanf("%d%d%d%d%d%d",&R,&C,&sx,&sy,&gx,&gy);
  sx--; sy--;
  gx--; gy--;

  char c[R][C+1];
  for(int i = 0;i < R;i++) scanf("%s",c[i]);

  int x,y;
  int xx,yy;

  int visited[R][C];
  for(int i = 0;i < R;i++){
    for(int j = 0;j < C;j++){
      visited[i][j] = -1;
    }
  }
  visited[sx][sy] = 0;
  push(sx*100+sy);

  while(1){
    int data = pop();
    if(data == -1) break;

    x = data/100;
    y = data%100;

    if(x == gx && y == gy) break;

    for(int i = 0;i < 4;i++){
      xx = x+vx[i];
      yy = y+vy[i];
      if(c[xx][yy] == '#') continue;
      if(0 <= xx && xx < R && 0 <= yy && yy < C){
        if(visited[xx][yy] == -1){
          visited[xx][yy] = visited[x][y]+1;
          push(xx*100+yy);
        }
      }
    }
  }

  printf("%d\n",visited[gx][gy]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d%d",&R,&C,&sx,&sy,&gx,&gy);
   ^
./Main.c:29:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < R;i++) scanf("%s",c[i]);
                            ^