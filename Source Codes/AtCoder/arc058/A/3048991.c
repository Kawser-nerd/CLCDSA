#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cond(int n,int *d){
  while(n>0){
    if(d[n%10]) return 0;
    n/=10;
  }
  return 1;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int d[10]={0};
  int i;
  for(i=0;i<k;i++){
    int c;
    scanf("%d",&c);
    d[c]=1;
  }
  while(!cond(n,d)) n++;
  printf("%d\n",n);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:26:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&c);
     ^