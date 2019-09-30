#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  if(n<m){
    int t=m;
    m=n;
    n=t;
  }
  if(n-m>1){
    printf("0\n");
    return;
  }
  const int mod=1000000007;
  int f=1;
  int i;
  for(i=1;i<=n;i++) f=(int64)f*i%mod;
  for(i=1;i<=m;i++) f=(int64)f*i%mod;
  if(n==m) f=2*f%mod;
  printf("%d\n",f);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^