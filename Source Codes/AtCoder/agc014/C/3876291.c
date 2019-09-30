#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*w+(j))
#define MIN(a,b) ((a)<(b)?(a):(b))

typedef struct point2d{
  int x,y;
} point;

int calc(point p,int h,int w,int k){
  int a=(p.x+k-1)/k;
  int b=(h-1-p.x+k-1)/k;
  int c=(p.y+k-1)/k;
  int d=(w-1-p.y+k-1)/k;
  return MIN(a,MIN(b,MIN(c,d)));
}

void run(void){
  int h,w,k;
  scanf("%d%d%d",&h,&w,&k);
  char *board=(char *)calloc(h*w+1,sizeof(char));
  int i,j;
  for(i=0;i<h;i++) scanf("%s",board+i*w);
  point s={0,0};
  for(i=0;i<h*w;i++){
    if(board[i]=='S'){
      s=(point){i/w,i%w};
      break;
    }
  }
  int min=h*w;
  point *now=(point *)calloc(h*w,sizeof(point));
  point *next=(point *)calloc(h*w,sizeof(point));
  int top=0;
  now[top++]=s;
  board[POS(s.x,s.y)]='#';
  for(i=0;i<=k;i++){
    int ntop=0;
    while(top>0){
      point t=now[--top];
      min=MIN(min,calc(t,h,w,k)+1);
      int d[]={1,0,-1,0};
      for(j=0;j<4;j++){
	int x=t.x+d[j];
	int y=t.y+d[j^1];
	if(0<=x && x<h && 0<=y && y<w && board[POS(x,y)]!='#'){
	  board[POS(x,y)]='#';
	  next[ntop++]=(point){x,y};
	}
      }
    }
    point *swap=now;
    now=next;
    next=swap;
    top=ntop;
  }
  printf("%d\n",min);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&h,&w,&k);
   ^
./Main.c:24:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<h;i++) scanf("%s",board+i*w);
                    ^