#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define POS(i,j) ((i)*a+(j))

int calc(int *a,int n,int64 *dp){
  int i,j;
  for(i=0;i<=50*n;i++) dp[i]=0;
  dp[0]=1;
  int sum=0;
  for(i=0;i<n;i++){
    for(j=sum;j>=0;j--){
      dp[j+a[i]]+=dp[j];
    }
    sum+=a[i];
  }
  return sum;
}

void run(void){
  int n,a;
  scanf("%d%d",&n,&a);
  int *minus=(int *)malloc(sizeof(int)*n);
  int *plus=(int *)malloc(sizeof(int)*n);
  int mlen=0;
  int plen=0;
  int eq=0;
  int i;
  for(i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    if(x==a){
      eq++;
    } else if(x<a){
      minus[mlen++]=a-x;
    } else {
      plus[plen++]=x-a;
    }
  }
  int64 *minusDP=(int64 *)malloc(sizeof(int64)*(50*mlen+1));
  int64 *plusDP =(int64 *)malloc(sizeof(int64)*(50*mlen+1));
  int mUP=calc(minus,mlen,minusDP);
  int pUP=calc(plus,plen,plusDP);
  int64 ans=0;
  for(i=0;i<=mUP && i<=pUP;i++){
    ans+=minusDP[i]*plusDP[i];
  }
  ans=(ans<<eq)-1;
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&a);
   ^
./Main.c:33:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^