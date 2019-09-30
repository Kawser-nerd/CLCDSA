#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int a,b,c,x,y;
  scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
  int ans=0;
  if(a+b>=2*c){
    while(x>0 && y>0){
      ans+=2*c;
      x--;
      y--;
    }
  }
  if(a>=2*c){
    ans+=2*c*x;
    y=MAX(y-x,0);
    x=0;
  }
  if(b>=2*c){
    ans+=2*c*y;
    x=MAX(x-y,0);
    y=0;
  }
  ans+=a*x+b*y;
  printf("%d\n",ans);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
   ^