#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

const int mod=1000000007;
int *fact=NULL;
int *ifact=NULL;
void init(int n){
  fact=(int *)malloc(sizeof(int)*(n+1));
  ifact=(int *)malloc(sizeof(int)*(n+1));
  fact[0]=1;
  int i;
  for(i=1;i<=n;i++) fact[i]=(int64)fact[i-1]*i%mod;
  int t=1;
  int s=fact[n];
  int m=mod-2;
  while(m>0){
    if(m&0x01) t=(int64)t*s%mod;
    s=(int64)s*s%mod;
    m>>=1;
  }
  ifact[n]=t;
  for(i=n-1;i>=0;i--) ifact[i]=(int64)ifact[i+1]*(i+1)%mod;
  return;
}

int comb(int n,int k){
  return (int64)fact[n]*ifact[k]%mod*ifact[n-k]%mod;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  init(n+100);
  int ans=1;
  int k;
  for(k=2;k*k<=m;k++){
    if(m%k==0){
      int c=0;
      while(m%k==0){
	c++;
	m/=k;
      }
      ans=(int64)ans*comb(n-1+c,c)%mod;
    }
  }
  if(m>1){
    ans=(int64)ans*comb(n-1+1,1)%mod;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^