#include <stdio.h>

typedef long long int ll;
int mod = 1000000007;

int dp[1001][1001];
int fact[1001];
int ifact[1001];

int modpow(int n, int k){
  if(k==0) return 1;
  if(k%2) return (ll) n * modpow((ll) n*n %mod, k/2) % mod;
  else return modpow((ll) n*n %mod, k/2);
}

int main(){
  int i, j, k, n, a, b, c, d;

  fact[0]=1;
  for(i=1;i<=1000;i++) fact[i] = (ll) i * fact[i-1] % mod;
  ifact[1000] = modpow(fact[1000], mod-2);
  for(i=999;i>=0;i--) ifact[i] = (ll) (i+1) * ifact[i+1] % mod;
  
  
  scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);

  for(j=0;j<=b-a;j++) dp[0][j] = 1;
  for(i=0;i<=n;i++){
    if((i%a==0) && (i/a>=c) && (i/a<=d)){
      dp[i][0] = (ll) fact[i] * ((ll) modpow(ifact[a], i/a) * ifact[i/a] % mod) % mod;
    }
  }

  for(i=1;i<=n;i++){
    for(j=1;j<=b-a;j++){
      int tmp = modpow(ifact[a+j], c);
      dp[i][j] = dp[i][j-1];
      for(k=c; k<=d && k*(a+j)<=i; k++){
        dp[i][j] += (ll) fact[i] * ((ll) tmp * ((ll) ifact[i-k*(a+j)] * ((ll) ifact[k] * dp[i-k*(a+j)][j-1] % mod) % mod) % mod) % mod;
        if(dp[i][j] >= mod) dp[i][j] -= mod;
        tmp = (ll) tmp * ifact[a+j] % mod;
      }
    }
  }

  printf("%d\n", dp[n][b-a]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
   ^