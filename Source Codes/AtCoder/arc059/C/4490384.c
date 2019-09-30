#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

const int mod=1000000007;

#define ADD(a,b) ((a)+(b)<mod?(a)+(b):(a)+(b)-mod)
#define MUL(a,b) ((int64)(a)*(b)%mod)

int modPow(int r,int n){
  int t=1;
  int s=r;
  while(n>0){
    if(n&1) t=MUL(t,s);
    s=MUL(s,s);
    n>>=1;
  }
  return t;
}

void run(void){
  int n,c;
  scanf("%d%d",&n,&c);
  int *a=(int *)calloc(2*n,sizeof(int));
  int *b=a+n;
  int i,j;
  for(i=0;i<2*n;i++) scanf("%d",a+i);
  const int m=400+1;
  int *pre=(int *)calloc(m*m,sizeof(int));
  for(i=1;i<m;i++) pre[i]=1;
  for(i=1;i<m;i++){
    for(j=1;j<m;j++){
      pre[i*m+j]=MUL(pre[(i-1)*m+j],j);
    }
  }
  for(i=0;i<m;i++){
    for(j=1;j<m;j++){
      pre[i*m+j]=ADD(pre[i*m+j],pre[i*m+j-1]);
    }
  }
  int *dp=(int *)calloc(c+1,sizeof(int));
  dp[0]=1;
  for(i=0;i<n;i++){
    for(j=c;j>=0;j--){
      int local=0;
      for(int k=0;k<=j;k++){
	local=ADD(local,MUL(dp[j-k],ADD(pre[k*m+b[i]],mod-pre[k*m+a[i]-1])));
      }
      dp[j]=local;
    }
  }
  printf("%d\n",dp[c]);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&c);
   ^
./Main.c:28:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<2*n;i++) scanf("%d",a+i);
                      ^