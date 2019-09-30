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
  int64 *a=(int64 *)malloc(sizeof(int64)*n);
  int64 *b=(int64 *)malloc(sizeof(int64)*n);
  int i;
  for(i=0;i<n;i++) scanf("%lld%lld",a+i,b+i);
  int64 cnt=0;
  for(i=n-1;i>=0;i--){
    if((a[i]+cnt)%b[i]==0) continue;
    cnt+=b[i]-(a[i]+cnt)%b[i];
  }
  printf("%lld\n",cnt);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:17:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%lld%lld",a+i,b+i);
                    ^