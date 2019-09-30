#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*w+(j))

typedef struct point2d{
  int x,y;
} point;

const int dx[]={1 ,1,1, 0,0,-1,-1,-1};
const int dy[]={-1,0,1,-1,1,-1, 0, 1};

void run(void){
  int h,w;
  scanf("%d%d",&h,&w);
  char *board=(char *)calloc(h*w+1,sizeof(char));
  int i,j;
  for(i=0;i<h;i++) scanf("%s",board+POS(i,0));
  point *s=(point *)calloc(h*w,sizeof(point));
  int cnt[16];
  cnt[1]=cnt[3]=cnt[11]=0;
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(board[POS(i,j)]=='.') continue;
      board[POS(i,j)]='.';
      int c=1;
      int top=0;
      s[top++]=(point){i,j};
      while(top>0){
	point p=s[--top];
	int k;
	for(k=0;k<8;k++){
	  int x=p.x+dx[k];
	  int y=p.y+dy[k];
	  if(0<=x && x<h && 0<=y && y<w && board[POS(x,y)]=='o'){
	    board[POS(x,y)]='.';
	    c++;
	    s[top++]=(point){x,y};
	  }
	}
      }
      int k;
      for(k=2;k*k<=c;k++) while(c%(k*k)==0) c/=k*k;
      cnt[c]++;
    }
  }
  printf("%d %d %d\n",cnt[3],cnt[1],cnt[11]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:18:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<h;i++) scanf("%s",board+POS(i,0));
                    ^