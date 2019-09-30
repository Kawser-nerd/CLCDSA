#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

typedef struct point2d{
  double x,y;
} point;

int cmp(const void *a,const void *b){
  const point *p=a;
  const point *q=b;
  return p->x==q->x?0:p->x<q->x?-1:1;
}

double dis(point *a,point *b){
  double dx=a->x-b->x;
  double dy=a->y-b->y;
  return sqrt(dx*dx+dy*dy);
}

double calc(point *p,int n){
  if(n<=3){
    double min=1000000000.0*2*2;
    int i,j;
    for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
	double l=dis(p+i,p+j);
	min=MIN(min,l);
      }
    }
    return min;
  }
  int m=n/2;
  double l1=calc(p,m);
  double l2=calc(p+m,n-m);
  double min=MIN(l1,l2);
  int s,t;
  s=m;
  while(s>0 && p[m].x-p[s-1].x<=min) s--;
  t=m;
  while(t<n && p[t].x-p[m-1].x<=min) t++;
  int i,j;
  for(i=s;i<m;i++){
    for(j=m;j<t;j++){
      double l=dis(p+i,p+j);
      min=MIN(min,l);
    }
  }
  return min;
}

void run(void){
  int n;
  scanf("%d",&n);
  point *p=(point *)calloc(n,sizeof(point));
  int i;
  for(i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
  srand((unsigned)time(NULL));
  double m=(double)rand()/RAND_MAX*M_PI;
  for(i=0;i<n;i++) p[i]=(point){cos(m)*p[i].x-sin(m)*p[i].y,sin(m)*p[i].x+cos(m)*p[i].y};
  qsort(p,n,sizeof(point),cmp);
  double r=calc(p,n);
  for(i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
  m=(double)rand()/RAND_MAX*M_PI;
  for(i=0;i<n;i++) p[i]=(point){cos(m)*p[i].x-sin(m)*p[i].y,sin(m)*p[i].x+cos(m)*p[i].y};
  qsort(p,n,sizeof(point),cmp);
  double ans=calc(p,n)/r;
  printf("%.7lf\n",ans);
  free(p);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:57:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:60:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
                    ^
./Main.c:66:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
                    ^