#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

const int mod=1000000007;

int modPow(int r,int n){
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
  int *cnt=(int *)calloc(n,sizeof(int));
  int a;
  scanf("%d",&a);
  if(a>0){
    printf("0\n");
    return;
  }
  cnt[0]++;
  int i;
  for(i=1;i<n;i++){
    scanf("%d",&a);
    if(a==0){
      printf("0\n");
      return;
    }
    cnt[a]++;
  }
  for(i=n-1;i>=1;i--){
    if(cnt[i]>0 && cnt[i-1]==0){
      printf("0\n");
      return;
    }
  }
  int ans=1;
  for(i=1;cnt[i]>0;i++){
    ans=(int64)ans*modPow(modPow(2,cnt[i-1])-1,cnt[i])%mod*modPow(2,(int64)cnt[i]*(cnt[i]-1)/2%(mod-1))%mod;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
./Main.c:32:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^