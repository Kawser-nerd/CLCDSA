#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct point2dwithcircle{
  int x,y,r;
} point;

double distance(point *a,point *b){
  int dx=a->x-b->x;
  int dy=a->y-b->y;
  int64 d=(int64)dx*dx+(int64)dy*dy;
  int64 r=a->r+b->r;
  if(d<=r*r) return 0;
  return (double)(d-r*r)/(sqrt(d)+r);
}

void run(void){
  point s,t;
  scanf("%d%d%d%d",&s.x,&s.y,&t.x,&t.y);
  s.r=0;
  t.r=0;
  int n;
  scanf("%d",&n);
  point *array=(point *)malloc(sizeof(point)*(n+2));
  array[0]=s;
  array[n+1]=t;
  int i;
  for(i=1;i<=n;i++) scanf("%d%d%d",&array[i].x,&array[i].y,&array[i].r);
  double *dp=(double *)malloc(sizeof(double)*(n+2));
  int *used=(int *)malloc(sizeof(int)*(n+2));
  for(i=0;i<=n+1;i++){
    dp[i]=1e18;
    used[i]=0;
  }
  dp[0]=0;
  for(i=1;i<=n+1;i++){
    int index;
    for(index=0;used[index]!=0;index++);
    double min=dp[index];
    int j;
    for(j=index+1;j<=n+1;j++){
      if(!used[j] && dp[j]<min){
	min=dp[j];
	index=j;
      }
    }
    used[index]=1;
    for(j=0;j<=n+1;j++){
      dp[j]=MIN(dp[j],dp[index]+distance(array+index,array+j));
    }
  }
  printf("%.10lf\n",dp[n+1]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&s.x,&s.y,&t.x,&t.y);
   ^
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:35:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++) scanf("%d%d%d",&array[i].x,&array[i].y,&array[i].r);
                     ^