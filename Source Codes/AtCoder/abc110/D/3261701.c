#include<stdio.h>

typedef long long int int64;

const int mod=1000000007;

int comb(int n,int k){
  int res=1;
  int inv[31];
  inv[1]=1;
  int i;
  for(i=1;i<=k;i++){
    if(i>=2) inv[i]=mod-(int64)(mod/i)*inv[mod%i]%mod;
    res=(int64)res*(n+1-i)%mod*inv[i]%mod;
  }
  return res;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
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
  if(m>1) ans=(int64)ans*comb(n-1+1,1)%mod;
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^