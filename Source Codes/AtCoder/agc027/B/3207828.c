#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define MIN(a,b) ((a)<(b)?(a):(b))

void run(void){
  int n,x;
  scanf("%d%d",&n,&x);
  int *a=(int *)malloc(sizeof(int)*(n+1));
  a[0]=0;
  int i;
  for(i=1;i<=n;i++) scanf("%d",a+i);
  int64 *sum=(int64 *)malloc(sizeof(int64)*(n+1));
  sum[0]=0;
  for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
  int64 ans=(int64)2*n*x+5*sum[n];
  for(i=1;i<=n;i++){
    const int k=i;
    int64 local=(int64)x*(n+k);
    int j;
    for(j=1;j<=n/k;j++){
      local+=(j==1?5:2*j+1)*(sum[n-k*(j-1)]-sum[n-k*j]);
      if(local>=ans) break;
    }
    if(j<=n/k) continue;
    if(n%k!=0) local+=(j==1?5:2*j+1)*sum[n%k];
    ans=MIN(local,ans);
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^
./Main.c:14:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++) scanf("%d",a+i);
                     ^