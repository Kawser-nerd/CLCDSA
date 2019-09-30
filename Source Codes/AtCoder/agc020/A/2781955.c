#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,a,b;
  scanf("%d%d%d",&n,&a,&b);
  if(ABS(a-b)==1 && (a==1 || a==n)){
    printf("Borys\n");
    return;
  }
  printf("%s\n",ABS(a-b-1)%2==0?"Borys":"Alice");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&a,&b);
   ^