#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

void run(void){
  int n;
  scanf("%d",&n);
  int x[1000],y[1000],c[1000];
  int i;
  for(i=0;i<n;i++) scanf("%d%d%d",x+i,y+i,c+i);
  double l=0;
  double r=200000*1000;
  for(i=0;i<200;i++){
    const double m=(l+r)/2;
    double lx=x[0]-m/c[0];
    double rx=x[0]+m/c[0];
    double ly=y[0]-m/c[0];
    double ry=y[0]+m/c[0];
    for(int j=1;j<n;j++){
      lx=MAX(lx,x[j]-m/c[j]);
      rx=MIN(rx,x[j]+m/c[j]);
      ly=MAX(ly,y[j]-m/c[j]);
      ry=MIN(ry,y[j]+m/c[j]);
    }
    if(lx<=rx && ly<=ry){
      r=m;
    } else {
      l=m;
    }
  }
  printf("%.9f\n",(l+r)/2);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:12:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d%d%d",x+i,y+i,c+i);
                    ^