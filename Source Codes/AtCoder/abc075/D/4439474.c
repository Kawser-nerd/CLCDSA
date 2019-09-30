#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define MIN(a,b) ((a)<(b)?(a):(b))

typedef struct point{
  int x,y;
} point;

int cmpPoint(const void *a,const void *b){
  point *p=(point *)a;
  point *q=(point *)b;
  if(p->x!=q->x) return p->x-q->x;
  return p->y-q->y;
}

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  point *p=(point *)calloc(n,sizeof(point));
  int i;
  for(i=0;i<n;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    p[i]=(point){x,y};
  }
  qsort(p,n,sizeof(point),cmpPoint);
  int64 min=4000000000000000000LL;
  for(i=0;i<n;i++){
    for(int j=i+k-1;j<n;j++){
      int dx=p[j].x-p[i].x;
      int y[50];
      int l;
      for(l=0;l<=j-i;l++){
	y[l]=p[i+l].y;
      }
      qsort(y,j-i+1,sizeof(int),cmp);
      int dy=y[k-1]-y[0];
      for(l=1;l+k-1<=j-i;l++) dy=MIN(dy,y[l+k-1]-y[l]);
      min=MIN(min,(int64)dx*dy);
    }
  }
  printf("%lld\n",min);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:30:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^