#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

const int mod=1000000007;

int *fact=NULL;
int *invFact=NULL;

int inv(int a,int p){
  if(a==1) return 1;
  return p-(int64)(p/a)*inv(p%a,p)%p;
}

void init(int n){
  fact=(int *)malloc(sizeof(int)*(n+1));
  invFact=(int *)malloc(sizeof(int)*(n+1));
  fact[0]=1;
  int i;
  for(i=1;i<=n;i++) fact[i]=(int64)fact[i-1]*i%mod;
  invFact[n]=inv(fact[n],mod);
  for(i=n-1;i>=0;i--){
    invFact[i]=(int64)invFact[i+1]*(i+1)%mod;
  }
  return;
}

int comb(int n,int k){
  int res=(int64)fact[n]*invFact[k]%mod*invFact[n-k]%mod;
  return res;
}

void run(void){
  int h,w,a,b;
  scanf("%d%d%d%d",&h,&w,&a,&b);
  init(h+w);
  int ans=0;
  int x,y;
  for(x=h-a-1,y=b;x>=0 && y<w;x--,y++){
    ans=(ans+(int64)comb(x+y,x)*comb(h-x-1+w-y-1,h-x-1))%mod;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&h,&w,&a,&b);
   ^