#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j,k) (((i)*10+(j))*10+(k))

void run(void){
  int n;
  scanf("%d",&n);
  int *h=(int *)calloc(n,sizeof(int));
  int i,j,k;
  for(i=0;i<n;i++) scanf("%d",h+i);
  const int mod=1000000007;
  const int batch=548;
  const int f=10;
  int *memo=(int *)calloc((n/batch)*f*f,sizeof(int));
  int *dp=(int *)calloc(n+10,sizeof(int));
  for(i=0;i<n/batch;i++){
    for(j=0;j<f;j++){
      memset(dp,0,sizeof(int)*(batch+10));
      dp[j]=1;
      for(k=j;k<batch;k++){
	for(int l=1;l<=h[i*batch+k];l++){
	  dp[k+l]+=dp[k];
	  if(dp[k+l]>=mod) dp[k+l]-=mod;
	}
      }
      for(k=0;k<f;k++) memo[POS(i,j,k)]=dp[batch+k];
    }
  }
  int d;
  scanf("%d",&d);
  while(d--){
    int s,t;
    scanf("%d%d",&s,&t);
    s--;
    t--;
    memset(dp,0,sizeof(int)*(n+10));
    dp[s]=1;
    if(t-s<=2*batch){
      for(i=s;i<t;i++){
	for(j=1;j<=h[i];j++){
	  dp[i+j]+=dp[i];
	  if(dp[i+j]>=mod) dp[i+j]-=mod;
	}
      }
      printf("%d\n",dp[t]);
    } else {
      for(i=s;i<(s+batch-1)/batch*batch;i++){
	for(j=1;j<=h[i];j++){
	  dp[i+j]+=dp[i];
	  if(dp[i+j]>=mod) dp[i+j]-=mod;
	}
      }
      for(;i+batch<=t;i+=batch){
	for(j=0;j<f;j++){
	  for(k=0;k<f;k++){
	    dp[i+batch+k]+=(int64)dp[i+j]*memo[POS(i/batch,j,k)]%mod;
	    if(dp[i+batch+k]>=mod) dp[i+batch+k]-=mod;
	  }
	}
      }
      for(;i<t;i++){
	for(j=1;j<=h[i];j++){
	  dp[i+j]+=dp[i];
	  if(dp[i+j]>=mod) dp[i+j]-=mod;
	}
      }
      printf("%d\n",dp[t]);
    }
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:18:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",h+i);
                    ^
./Main.c:38:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&d);
   ^
./Main.c:41:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&s,&t);
     ^