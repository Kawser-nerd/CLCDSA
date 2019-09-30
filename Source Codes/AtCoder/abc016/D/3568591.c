#include<stdio.h>
#include<stdlib.h>

typedef struct point2d{
  int x,y;
} point;

typedef struct line2d{
  point s,t;
} line;

int sign(line l,point p){
  int d=(l.t.y-l.s.y)*(p.x-l.s.x)-(l.t.x-l.s.x)*(p.y-l.s.y);
  return d==0?0:d<0?-1:1;
}

int hasInterSection(line a,line b){
  return sign(a,b.s)*sign(a,b.t)<0 && sign(b,a.s)*sign(b,a.t)<0;
}

void run(void){
  line l;
  scanf("%d%d%d%d",&l.s.x,&l.s.y,&l.t.x,&l.t.y);
  int n;
  scanf("%d",&n);
  point p[100];
  int i;
  for(i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
  int cnt=0;
  for(i=0;i<n;i++){
    if(hasInterSection(l,(line){p[i],p[(i+1)%n]})) cnt++;
  }
  printf("%d\n",1+cnt/2);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&l.s.x,&l.s.y,&l.t.x,&l.t.y);
   ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:28:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
                    ^