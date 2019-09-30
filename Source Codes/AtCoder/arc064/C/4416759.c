#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

typedef struct point{
  int x,y,r;
} point;

double distance(point a,point b){
  double dx=a.x-b.x;
  double dy=a.y-b.y;
  double l=sqrt(dx*dx+dy*dy);
  return MAX(0,l-a.r-b.r);
}

void run(void){
  point s,t;
  scanf("%d%d%d%d",&s.x,&s.y,&t.x,&t.y);
  s.r=t.r=0;
  int n;
  scanf("%d",&n);
  const int m=n+2;
  point *p=(point *)calloc(m,sizeof(point));
  p[0]=s;
  p[m-1]=t;
  int i;
  for(i=1;i<=n;i++){
    int x,y,r;
    scanf("%d%d%d",&x,&y,&r);
    p[i]=(point){x,y,r};
  }
  double *dp=(double *)calloc(m,sizeof(double));
  for(i=1;i<m;i++) dp[i]=2000000000*sqrt(2)*2;
  int *used=(int *)calloc(m,sizeof(int));
  for(i=0;i<m;i++){
    int j;
    for(j=0;used[j];j++);
    int min=j;
    for(j=min+1;j<m;j++) if(used[j]==0 && dp[j]<dp[min]) min=j;
    used[min]=1;
    for(j=0;j<m;j++){
      if(used[j]) continue;
      double d=distance(p[min],p[j]);
      if(dp[j]>dp[min]+d){
	dp[j]=dp[min]+d;
      }
    }
  }
  printf("%.10f\n",dp[m-1]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&s.x,&s.y,&t.x,&t.y);
   ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&x,&y,&r);
     ^