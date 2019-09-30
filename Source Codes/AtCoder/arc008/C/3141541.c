#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

typedef struct person{
  int x,y;
  int t,r;
} node;

double calc(node *from,node *to){
  int dx=from->x-to->x;
  int dy=from->y-to->y;
  double l=sqrt(dx*dx+dy*dy);
  int v=MIN(from->t,to->r);
  return l/v;
}

int cmp(const void *a,const void *b){
  return *(double *)a<=*(double *)b?-1:1;
}

void run(void){
  int n;
  scanf("%d",&n);
  node *p=(node *)malloc(sizeof(node)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d%d%d%d",&p[i].x,&p[i].y,&p[i].t,&p[i].r);
  double *dp=(double *)malloc(sizeof(double)*n);
  int *used=(int *)calloc(n,sizeof(int));
  const double inf=30000;
  for(i=0;i<n;i++) dp[i]=inf;
  dp[0]=0;
  for(i=0;i<n-1;i++){
    int index=-1;
    int j;
    for(j=0;j<n;j++){
      if(!used[j] && (index==-1 || dp[index]>dp[j])){
	index=j;
      }
    }
    if(index==-1) break;
    for(j=0;j<n;j++){
      double s=calc(p+index,p+j);
      dp[j]=MIN(dp[j],dp[index]+s);
    }
    used[index]=1;
  }
  qsort(dp+1,n-1,sizeof(double),cmp);
  double min=dp[n-1];
  for(i=n-2;i>=1;i--){
    min=MAX(min,dp[i]+(n-1-i));
  }
  printf("%.9lf\n",min);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:30:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d%d%d%d",&p[i].x,&p[i].y,&p[i].t,&p[i].r);
                    ^