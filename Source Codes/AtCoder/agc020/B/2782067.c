#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int k;
  scanf("%d",&k);
  int *a=(int *)malloc(sizeof(int)*k);
  int i;
  for(i=0;i<k;i++) scanf("%d",a+i);
  if(a[k-1]!=2){
    printf("-1\n");
    return;
  }
  int64 min,max;
  min=2;
  max=3;
  for(i=k-2;i>=0;i--){
    int64 t=(min+a[i]-1)/a[i]*a[i];
    if(!(t/a[i]*a[i]<=max)){
      printf("-1\n");
      return;
    }
    min=t;
    max=max/a[i]*a[i]+a[i]-1;
  }
  printf("%lld %lld\n",min,max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^
./Main.c:16:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<k;i++) scanf("%d",a+i);
                    ^