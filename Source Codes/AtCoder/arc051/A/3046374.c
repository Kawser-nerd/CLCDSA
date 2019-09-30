#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int distance(int dx,int dy){
  return dx*dx+dy*dy;
}

void run(void){
  int x1,y1,r;
  scanf("%d%d%d",&x1,&y1,&r);
  int x2,x3,y2,y3;
  scanf("%d%d%d%d",&x2,&y2,&x3,&y3);
  x2-=x1;
  x3-=x1;
  y2-=y1;
  y3-=y1;
  if(-r<x2 || x3<r || -r<y2 || y3<r){
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  int rr=r*r;
  if(distance(x2,y2)>rr || distance(x2,y3)>rr || distance(x3,y2)>rr || distance(x3,y3)>rr){
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&x1,&y1,&r);
   ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&x2,&y2,&x3,&y3);
   ^