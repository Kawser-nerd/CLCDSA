#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  int64 c;
  scanf("%d%lld",&n,&c);
  int i;
  int64 x[100000];
  int v[100000];
  for(i=0;i<n;i++){
    scanf("%lld%d",x+i,v+i);
  }

  int64 f[100000];
  int64 max=MAX(0,v[0]-x[0]);;
  int64 sum=v[0];
  f[0]=max;
  for(i=1;i<n;i++){
    sum+=v[i];
    max=MAX(max,sum-x[i]);
    f[i]=max;
  }
  sum=0;
  for(i=n-1;i>=0;i--){
    sum+=v[i];
    max=MAX(max,sum-(c-x[i]));
    if(i-1>=0){
      max=MAX(max,sum-2*(c-x[i])+f[i-1]);
    }
  }

  f[n-1]=MAX(0,v[n-1]-(c-x[n-1]));
  sum=v[n-1];
  for(i=n-2;i>=0;i--){
    sum+=v[i];
    f[i]=MAX(f[i+1],sum-(c-x[i]));
  }
  sum=0;
  for(i=0;i<n-1;i++){
    sum+=v[i];
    max=MAX(max,sum-2*x[i]+f[i+1]);
  }

  printf("%lld\n",max);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%lld",&n,&c);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%d",x+i,v+i);
     ^