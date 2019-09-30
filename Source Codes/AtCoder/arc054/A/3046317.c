#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int l,x,y,s,d;
  scanf("%d%d%d%d%d",&l,&x,&y,&s,&d);
  double len=d>=s?d-s:l-s+d;
  double sec=len/(x+y);
  if(y>x){
    len=d>=s?s+l-d:s-d;
    sec=MIN(sec,len/(y-x));
  }
  printf("%.7lf\n",sec);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d",&l,&x,&y,&s,&d);
   ^