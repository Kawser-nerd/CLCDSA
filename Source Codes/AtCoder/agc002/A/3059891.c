#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

//a<=b
int calc(int a,int b){
  if(a>0) return 1;
  //a<=0
  if(b>=0) return 0;
  //a<=b<0
  return (b-a)%2==1?1:-1;
}

void run(void){
  int a,b;
  scanf("%d%d",&a,&b);
  int c=calc(a,b);
  printf("%s\n",c==0?"Zero":c==1?"Positive":"Negative");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^