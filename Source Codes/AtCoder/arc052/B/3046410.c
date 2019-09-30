#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,q;
  scanf("%d%d",&n,&q);
  const double pi=3.141592653589793;
  double *sum=(double *)calloc(10000*2+2,sizeof(double));
  while(n--){
    int x,r,h;
    scanf("%d%d%d",&x,&r,&h);
    int i;
    for(i=x+h-1;i>=x;i--){
      double hh=x+h-i;
      double rr=(double)r/h*hh;
      sum[i]+=pi*rr*rr*hh/3;
    }
    while(i>=0){
      sum[i--]+=pi*r*r*h/3;
    }
  }
  while(q--){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%.4lf\n",sum[a]-sum[b]);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&q);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&x,&r,&h);
     ^
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^