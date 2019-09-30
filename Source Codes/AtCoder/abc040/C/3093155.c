#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  int ab,ac;
  scanf("%d%d",&ab,&ac);
  int64 b=0;
  int64 c=ABS(ac-ab);
  int i;
  for(i=n-3;i>=0;i--){
    int ad;
    scanf("%d",&ad);
    int64 d=MIN(ABS(ac-ad)+c,ABS(ad-ab)+b);
    b=c;
    c=d;
    ab=ac;
    ac=ad;
  }
  printf("%lld\n",c);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&ab,&ac);
   ^
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&ad);
     ^