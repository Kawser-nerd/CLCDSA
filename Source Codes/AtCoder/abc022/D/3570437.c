#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct point2d{
  double x,y;
} point;

double dis(point *a,point *b){
  double dx=a->x-b->x;
  double dy=a->y-b->y;
  return sqrt(dx*dx+dy*dy);
}

double calc(point *p,int n){
  double x=0;
  double y=0;
  int i;
  for(i=0;i<n;i++){
    x+=p[i].x;
    y+=p[i].y;
  }
  x/=n;
  y/=n;
  double max=0;
  for(i=0;i<n;i++){
    double l=dis(p+i,&((point){x,y}));
    if(l>max) max=l;
  }
  return max;
}

void run(void){
  int n;
  scanf("%d",&n);
  point *p=(point *)calloc(n,sizeof(point));
  int i;
  for(i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
  double r=calc(p,n);
  for(i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
  double ans=calc(p,n)/r;
  printf("%.7lf\n",ans);
  free(p);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:38:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
                    ^
./Main.c:40:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
                    ^