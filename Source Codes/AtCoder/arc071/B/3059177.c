#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

const int mod=1000000007;

int func(int *a,int n){
  int sum=0;
  int i;
  for(i=0;i<n-1;i++) sum=(sum+(int64)(a[i+1]-a[i])*(i+1)%mod*(n-1-i)%mod)%mod;
  return sum;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *x=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",x+i);
  int *y=(int *)malloc(sizeof(int)*m);
  for(i=0;i<m;i++) scanf("%d",y+i);

  int ans=(int64)func(x,n)*func(y,m)%mod;
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:25:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",x+i);
                    ^
./Main.c:27:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<m;i++) scanf("%d",y+i);
                    ^