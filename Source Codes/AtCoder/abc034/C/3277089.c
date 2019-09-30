#include<stdio.h>

typedef long long int int64;

const int mod=1000000007;

int comb(int n,int k){
  int a=1;
  int b=1;
  int i;
  for(i=1;i<=k;i++){
    a=(int64)a*(n+1-i)%mod;
    b=(int64)b*i%mod;
  }
  int t=1;
  while(b>1){
    t=(int64)t*(mod-mod/b)%mod;
    b=mod%b;
  }
  return (int64)a*t%mod;
}

void run(void){
  int w,h;
  scanf("%d%d",&w,&h);
  int ans=comb(w-1+h-1,w-1);
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&w,&h);
   ^