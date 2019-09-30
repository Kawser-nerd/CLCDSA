#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

void run(void){
  int n,m,q;
  scanf("%d%d%d",&n,&m,&q);
  int *a=(int *)calloc(n,sizeof(int));
  int i,j;
  for(i=0;i<n;i++) scanf("%d",a+i);
  const int mod=1000000007;
  int *dp=(int *)calloc(2*m+2,sizeof(int))+m+1;
  dp[0]=1;
  for(i=0;i<n;i++){
    int aa=a[i];
    int sum=0;
    for(j=m;j>=m-aa;j--){
      sum=(sum+dp[j])%mod;
    }
    for(j=m;j>=0;j--){
      int next=((int64)sum-dp[j]+dp[j-aa-1]+mod)%mod;
      dp[j]=sum;
      sum=next;
    }
  }
  int *dp2=(int *)calloc(n*(m+1),sizeof(int));
  for(i=0;i<n;i++){
    int aa=a[i];
    for(j=0;j<aa+1;j++){
      dp2[i*(m+1)+j]=(dp[j]-dp[j-1]+mod)%mod;
    }
    for(j=aa+1;j<=m;j++){
      dp2[i*(m+1)+j]=((int64)dp[j]-dp[j-1]+mod+dp2[i*(m+1)+j-aa-1])%mod;
    }
  }
  while(q--){
    int k,x;
    scanf("%d%d",&k,&x);
    k--;
    printf("%d\n",dp2[k*(m+1)+m-x]);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&m,&q);
   ^
./Main.c:11:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^
./Main.c:39:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&k,&x);
     ^