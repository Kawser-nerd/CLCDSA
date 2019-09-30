#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define POS(i,j) ((i)*(2*50*n+1)+(j)+50*n)

void run(void){
  int n,a;
  scanf("%d%d",&n,&a);
  int64 *dp=(int64 *)calloc(2*50*n+1,sizeof(int64));
  int now=0;
  dp[POS(0,0)]=1;
  int l,r;
  l=r=0;
  int i,j;
  for(i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    x-=a;
    int next=now^1;
    for(j=l;j<=r;j++) dp[POS(next,j)]=dp[POS(now,j)];
    for(j=l;j<=r;j++) dp[POS(next,j+x)]+=dp[POS(now,j)];
    if(x<0){
      l+=x;
    } else {
      r+=x;
    }
    now=next;
  }
  printf("%lld\n",dp[POS(now,0)]-1);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&a);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^