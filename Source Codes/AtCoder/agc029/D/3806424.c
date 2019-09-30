#include<stdio.h>
#include<stdlib.h>

typedef struct point2d{
  int x,y;
} point;

int cmp(const void *a,const void *b){
  point *p=(point *)a;
  point *q=(point *)b;
  if(p->x!=q->x) return p->x-q->x;
  return p->y-q->y;
}

void run(void){
  int h,w,n;
  scanf("%d%d%d",&h,&w,&n);
  point *p=(point *)calloc(n,sizeof(point));
  int i;
  for(i=0;i<n;i++){
    scanf("%d%d",&p[i].y,&p[i].x);
  }
  qsort(p,n,sizeof(point),cmp);
  int min=h;
  int now=1;
  int k=0;
  for(i=1;i<=w && k<n;i++){
    while(k<n && p[k].x<i) k++;
    while(k<n && p[k].x==i && p[k].y<now) k++;
    while(k<n && p[k].x==i && p[k].y==now){
      now++;
      k++;
    }
    if(k<n && p[k].x==i && p[k].y>now){
      if(min>p[k].y-1) min=p[k].y-1;
    }
    now++;
  }
  printf("%d\n",min);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&h,&w,&n);
   ^
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&p[i].y,&p[i].x);
     ^