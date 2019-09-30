#include <stdio.h>
#include <math.h>
#define mod 1000000007

long int waru(long int ue, long int sita){
  if(ue==sita){
    return 1;
  }
  if(ue%sita==0){
    return (ue/sita)%mod;
  }
  return waru(ue+mod,sita);
}


long int comb(int q,int N){
  long int ue=1;
  long int sita=1;
  int i;
  for(i=0;i<q;i++){
    ue=ue*(q+N-1-i)%mod;
    sita=sita*(q-i)%mod;
  }
  
  return waru(ue,sita)%mod;
}
  

int main(){
  int N;
  long long int M;
  scanf("%d%lld",&N,&M);
  int i,t;
  long long int ans=1;
  for(i=2;i<=M;i++){
    if(M%i==0){
      t=0;
      while(M%i==0){
	M=M/i;
	t=t+1;
      }
      ans=ans*(comb(t,N))%mod;
    }
  }

  printf("%lld",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%lld",&N,&M);
   ^