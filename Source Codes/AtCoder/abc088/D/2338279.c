#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*w+(j))

void run(void){
  int h,w;
  scanf("%d%d",&h,&w);
  char *board=(char *)malloc(sizeof(char)*(h*w+1));
  int i,j;
  for(i=0;i<h;i++){
    scanf("%s",board+POS(i,0));
  }
  int cnt=0;
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(board[POS(i,j)]=='.') cnt++;
    }
  }
  int x[10001];
  int y[10001];
  int d[10001];
  x[0]=0;
  y[0]=0;
  d[0]=1;
  int ans=-1;
  int first=0;
  int last=1;
  while(first<last){
    int a=x[first];
    int b=y[first];
    int depth=d[first];
    first++;
    if((!(0<=a && a<h && 0<=b && b<w)) || board[POS(a,b)]=='#') continue;
    if(a==h-1 && b==w-1){
      ans=depth;
      break;
    }
    board[POS(a,b)]='#';
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    for(i=0;i<4;i++){
      x[last]=a+dx[i];
      y[last]=b+dy[i];
      d[last]=depth+1;
      last++;
    }
  }
  if(ans!=-1){
    printf("%d\n",cnt-ans);
  } else {
    printf("-1\n");
  }
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",board+POS(i,0));
     ^