#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*w+(j))

void run(void){
  int h,w,n;
  scanf("%d%d%d",&h,&w,&n);
  int a[10001];
  int i;
  for(i=1;i<=n;i++) scanf("%d",a+i);
  int board[10000];
  for(i=0;i<h*w;i++) board[i]=-1;
  int dx[]={1,0,-1,0};
  int dy[]={0,1,0,-1};
  int x,y;
  x=y=0;
  int dir=0;
  int index=0;
  while(index<=n){
    while(a[index]>0){
      board[POS(x,y)]=index;
      a[index]--;
      int nx=x+dx[dir];
      int ny=y+dy[dir];
      if(!(nx>=0 && nx<h && ny>=0 && ny<w && board[POS(nx,ny)]==-1)){
	dir=(dir+1)%4;
	nx=x+dx[dir];
	ny=y+dy[dir];
      }
      x=nx;
      y=ny;
    }
    index++;
  }
  for(i=0;i<h;i++){
    int j;
    for(j=0;j<w;j++){
      printf("%d ",board[POS(i,j)]);
    }
    printf("\n");
  }
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&h,&w,&n);
   ^
./Main.c:18:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++) scanf("%d",a+i);
                     ^