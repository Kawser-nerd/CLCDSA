#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int64 calc(int64 *x,int *v,int n,int64 c){
  int64 max=0;
  int64 sum=0;
  int i;
  for(i=0;i<n;i++){
    sum+=v[i];
    max=MAX(max,sum-x[i]);
  }
  int64 *y=(int64 *)calloc(n,sizeof(int64));
  y[0]=v[0]-x[0];
  sum=v[0];
  for(i=1;i<n;i++){
    sum+=v[i];
    y[i]=MAX(y[i-1],sum-x[i]);
  }
  sum=0;
  for(i=n-1;i>0;i--){
    sum+=v[i];
    max=MAX(max,sum-2*(c-x[i])+y[i-1]);
  }
  free(y);
  return max;
}

void run(void){
  int n;
  int64 c;
  scanf("%d%lld",&n,&c);
  int64 *x=(int64 *)calloc(n,sizeof(int64));
  int *v=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%lld%d",x+i,v+i);
  int64 a=calc(x,v,n,c);
  for(i=0;i<n-1-i;i++){
    int64 t=c-x[i];
    x[i]=c-x[n-1-i];
    x[n-1-i]=t;
    t=v[i];
    v[i]=v[n-1-i];
    v[n-1-i]=(int)t;
  }
  int64 b=calc(x,v,n,c);
  printf("%lld\n",MAX(a,b));
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:38:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%lld",&n,&c);
   ^
./Main.c:42:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%lld%d",x+i,v+i);
                    ^