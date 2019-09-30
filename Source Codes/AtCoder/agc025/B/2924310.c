#include<stdio.h>
#define mod 998244353
#define maxn 300005

long long fact[maxn];
 
void myfact(){
  long long i;
  fact[0]=1;
  for(i=1;i<maxn;i++) fact[i] = fact[i-1] * i % mod;
  return;
}
 
long long mypow(long long a, long long b){
  long long ans = 1;
  while(b != 0){
    if(b & 1) ans = ans*a % mod;
    a = a*a % mod;
    b = b >> 1;
  }
  return ans;
}       
 
long long mycomb(long long n, long long r){
  if(n<r || n<0 || r<0) return 0;
  else return (fact[n]*mypow(fact[r], mod-2)%mod)*mypow(fact[n-r], mod-2)%mod;
}

int main(){
  myfact();

  long long n, a, b, k;
  scanf("%lld %lld %lld %lld",&n,&a,&b,&k);

  long long i, ans = 0;
  for(i=0;i<=n;i++){
    if(k-i*a<0) break;
    if((k-i*a)%b==0 && (k-i*a)/b<=n){
      ans += mycomb(n, i) * mycomb(n, (k-i*a)/b) % mod;
      ans %= mod;
    }
  }
  
  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld %lld",&n,&a,&b,&k);
   ^