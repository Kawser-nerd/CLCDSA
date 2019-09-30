#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

double func(double x,double p){
  return x+p/pow(2,x/1.5);
}

void run(void){
  double p;
  scanf("%lf",&p);
  double l=0;
  double r=p;
  const int iter=1000;
  int i;
  for(i=0;i<iter;i++){
    double ll=(2*l+r)/3;
    double fl=func(ll,p);
    double rr=(l+2*r)/3;
    double fr=func(rr,p);
    if(fl<=fr){
      r=rr;
    } else {
      l=ll;
    }
  }
  printf("%.9lf\n",func((l+r)/2,p));
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf",&p);
   ^