#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,a,b,c,d;
  scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
  int i;
  for(i=0;i<=n-1;i++){
    int64 min=a+(int64)c*i-(int64)d*(n-1-i);
    int64 max=a+(int64)d*i-(int64)c*(n-1-i);
    if(b>=min && b<=max){
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
   ^