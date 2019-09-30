#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

const int mod=1000000007;

int modPow(int r,int64 n){
  int t=1;
  int s=r;
  while(n>0){
    if(n&1) t=(int64)t*s%mod;
    s=(int64)s*s%mod;
    n>>=1;
  }
  return t;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  if(a[0]>0){
    puts("0");
    return;
  }
  int *cnt=(int *)calloc(n,sizeof(int));
  for(i=0;i<n;i++) cnt[a[i]]++;
  if(cnt[0]>1){
    puts("0");
    return;
  }
  int sum=1;
  int ans=1;
  for(i=1;i<n && cnt[i]>0;i++){
    int before=cnt[i-1];
    int now=cnt[i];
    int a=modPow(modPow(2,before)-1,now);
    int b=modPow(2,(int64)now*(now-1)/2);
    ans=(int64)ans*a%mod*b%mod;
    sum+=cnt[i];
  }
  printf("%d\n",sum==n?ans:0);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:24:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^