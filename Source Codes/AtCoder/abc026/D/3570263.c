#include<stdio.h>
#include<math.h>

void run(void){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  const double pi=M_PI;
  double l=0;
  double r=200;
  for(int iter=0;iter<200;iter++){
    double m=(l+r)/2;
    if(a*m+b*sin(c*m*pi)<=100){
      l=m;
    } else {
      r=m;
    }
  }
  printf("%.15lf\n",l);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^