#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

const int mod=1000000007;

#define F 10

typedef struct mat{
  int v[F*F];
} mat;

void run(void){
  int n;
  scanf("%d",&n);
  int *h=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",h+i);
  const int f=10;
  const int batch=1000;
  mat *b=(mat *)calloc((n+batch-1)/n,sizeof(mat));
  for(i=0;i+batch<n;i+=batch){
    mat t;
    int j,k;
    for(j=0;j<f;j++){
      for(k=0;k<f;k++){
	t.v[j*f+k]=(j==k?1:0);
      }
    }
    for(j=i;j<i+batch;j++){
      mat s;
      for(k=0;k<f*f;k++) s.v[k]=0;
      int l;
      for(k=1;k<f;k++){
	for(l=0;l<f;l++){
	  s.v[(k-1)*f+l]=t.v[k*f+l];
	}
      }
      for(k=0;k<h[j];k++){
	for(l=0;l<f;l++){
	  s.v[k*f+l]+=t.v[0*f+l];
	  s.v[k*f+l]%=mod;
	}
      }
      t=s;
    }
    b[i/batch]=t;
  }
  int d;
  scanf("%d",&d);
  while(d--){
    int l,r;
    scanf("%d%d",&l,&r);
    l--; r--;
    int dp[10]={1,0,0,0,0,0,0,0,0,0};
    for(i=l;i<r && i<(l+batch-1)/batch*batch;i++){
      int next[10]={0,0,0,0,0,0,0,0,0,0};
      int j;
      for(j=1;j<f;j++) next[j-1]=dp[j];
      for(j=0;j<h[i];j++) next[j]=(next[j]+dp[0])%mod;
      for(j=0;j<f;j++) dp[j]=next[j];
    }
    for(;i<r/batch*batch;i+=batch){
      int next[10]={0,0,0,0,0,0,0,0,0,0};
      int j,k;
      for(j=0;j<f;j++){
	for(k=0;k<f;k++){
	  next[j]=(next[j]+(int64)b[i/batch].v[j*f+k]*dp[k])%mod;
	}
      }
      for(j=0;j<f;j++) dp[j]=next[j];
    }
    for(;i<r;i++){
      int next[10]={0,0,0,0,0,0,0,0,0,0};
      int j;
      for(j=1;j<f;j++) next[j-1]=dp[j];
      for(j=0;j<h[i];j++) next[j]=(next[j]+dp[0])%mod;
      for(j=0;j<f;j++) dp[j]=next[j];
    }
    printf("%d\n",dp[0]);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:19:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",h+i);
                    ^
./Main.c:51:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&d);
   ^
./Main.c:54:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&l,&r);
     ^