#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)calloc(n,sizeof(int));
  int i,j;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int64 *dp=(int64 *)calloc(n+1,sizeof(int64));
  dp[n-1]=a[n-1];
  dp[n-2]=a[n-2];
  for(i=n-3;i>=0;i--){
    int64 local=a[i];
    for(j=i+2;j<=n;j+=2) local=MAX(local,dp[j]+a[i]);
    dp[i]=local;
  }
  int max=0;
  for(i=1;i<n;i++) if(dp[max]<dp[i]) max=i;
  printf("%lld\n",dp[max]);
  int *q=(int *)calloc(n,sizeof(int));
  int cnt=n;
  int len=0;
  for(i=0;i<max;i++){
    q[len++]=1;
    cnt--;
  }
  int now=max;
  while(now<n-2 && a[now]!=dp[now]){
    for(i=now+2;i<n;i+=2){
      if(dp[now]==dp[i]+a[now]){
	q[len++]=2;
	now=i;
	cnt-=2;
	break;
      } else {
	q[len++]=3;
	cnt-=2;
      }
    }
  }
  for(i=now+1;i<n;i++){
    q[len++]=cnt--;
  }
  printf("%d\n",len);
  for(i=0;i<len;i++) printf("%d\n",q[i]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:13:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^