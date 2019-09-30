#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  if(a%2==0 || b%2==0 || c%2==0){
    printf("0\n");
  } else {
    int x=MIN(a,MIN(b,c));
    int y=MIN(a,b)+MIN(b,c)+MIN(c,a)-2*x;
    printf("%lld\n",(int64)x*y);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^