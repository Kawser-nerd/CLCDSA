#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*w+(j))

int func(int i,int j,char *board,int h,int w){
  int k;
  for(k=0;k<h;k++){
    if(board[POS(k,i)]!=board[POS(h-1-k,j)]) return 0;
  }
  return 1;
}

int calcCol(char *board,int h,int w){
  int flag[16];
  int i,j;
  for(i=0;i<w;i++) flag[i]=0;
  int useCenter=0;
  for(i=0;i<w;i++){
    if(flag[i]) continue;
    for(j=i+1;j<w;j++){
      if(flag[j]) continue;
      if(func(i,j,board,h,w)){
	flag[i]=1;
	flag[j]=1;
	break;
      }
    }
    if(flag[i]==0){
      if(w%2==0 || useCenter) return 0;
      for(j=0;j<h-1-j;j++){
	if(board[POS(j,i)]!=board[POS(h-1-j,i)]) return 0;
      }
      useCenter=1;
      flag[i]=1;
    }
  }
  return 1;
}

void swapRow(int a,int b,char *board,int h,int w){
  int i;
  for(i=0;i<w;i++){
    char t=board[POS(a,i)];
    board[POS(a,i)]=board[POS(b,i)];
    board[POS(b,i)]=t;
  }
  return;
}

int loopRow(int d,char *board,int h,int w){
  if(d>=h-d-1) return calcCol(board,h,w);
  int i,j;
  for(i=d;i<h-d;i++){
    for(j=i+1;j<h-d;j++){
      swapRow(d,i,board,h,w);
      swapRow(h-d-1,j,board,h,w);
      if(loopRow(d+1,board,h,w)) return 1;
      swapRow(d,i,board,h,w);
      swapRow(h-d-1,j,board,h,w);
    }
  }
  return 0;
}

int calc(char *board,int h,int w){
  return loopRow(0,board,h,w);
}

void run(void){
  int h,w;
  scanf("%d%d",&h,&w);
  char *board=(char *)malloc(sizeof(char)*(h*w+1));
  int i;
  for(i=0;i<h;i++) scanf("%s",board+POS(i,0));
  printf("%s\n",calc(board,h,w)?"YES":"NO");
  free(board);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:79:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:82:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<h;i++) scanf("%s",board+POS(i,0));
                    ^