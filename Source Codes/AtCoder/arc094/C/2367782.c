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
  int *a=(int *)malloc(sizeof(int)*n);
  int *b=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d%d",a+i,b+i);
  for(i=0;i<n && a[i]==b[i];i++);
  if(i==n){
    printf("0\n");
    return;
  }
  int64 sum=0;
  for(i=0;i<n;i++) sum+=a[i];
  int min=1000000000;
  for(i=0;i<n;i++){
    if(a[i]-b[i]>0 && min>b[i]){
      min=b[i];
    }
  }
  printf("%lld\n",sum-min);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:17:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d%d",a+i,b+i);
                    ^