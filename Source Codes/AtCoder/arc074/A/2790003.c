#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int h,w;
  scanf("%d%d",&h,&w);
  if(h%3==0 || w%3==0){
    printf("0\n");
    return;
  }
  int min=MIN(h,w);
  int i;
  for(i=1;i<=w-1;i++){
    int64 a=(int64)i*h;
    int64 b=(int64)(w-i)*(h/2);
    int64 c=(int64)(w-i)*(h-h/2);
    min=MIN(min,MAX(a,MAX(b,c))-MIN(a,MIN(b,c)));
  }
  int swap=h;
  h=w;w=swap;
  for(i=1;i<=w-1;i++){
    int64 a=(int64)i*h;
    int64 b=(int64)(w-i)*(h/2);
    int64 c=(int64)(w-i)*(h-h/2);
    min=MIN(min,MAX(a,MAX(b,c))-MIN(a,MIN(b,c)));
  }
  printf("%d\n",min);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^