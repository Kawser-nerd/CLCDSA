#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int a,b;
  scanf("%d%d",&a,&b);
  const int mod=1000000007;
  int64 ans=1;
  int cnt[101]={0};
  int i;
  for(i=b+1;i<=a;i++){
    int t=i;
    int k;
    for(k=2;k*k<=t;k++){
      if(t%k!=0) continue;
      int c=0;
      while(t%k==0){
	t/=k;
	c++;
      }
      if(k<=100){
	cnt[k]+=c;
      } else {
	ans=ans*(c+1)%mod;
      }
    }
    if(t>1){
      if(t<=100){
	cnt[t]++;
      } else {
	ans=ans*2%mod;
      }
    }
  }
  for(i=2;i<=100;i++) ans=ans*(cnt[i]+1)%mod;
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^