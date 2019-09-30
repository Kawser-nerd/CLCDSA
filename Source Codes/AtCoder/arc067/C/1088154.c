#include <stdio.h>
#include <stdlib.h>

#define Q 1000000007
#define N 1001

typedef long long int ll;
ll dp[N][N];
ll fact[N], ifact[N], inv[N];
ll ifp[N][N];

ll power(ll a, ll b){
	ll s=1;
	
	while(b){
		if(b & 1) s = s * a % Q;
		a = a * a % Q;
		b = b >> 1;
	}
	
	return s;
}

int main(void){
	int n, a, b, c, d;
	int i, j, k;
	ll tmp;

	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
	fact[0] = 1;
	ifact[0] = 1;
	for(i=1; i<N; i++) inv[i]  = power(i, Q-2);
	for(i=1; i<N; i++) fact[i] = i * fact[i-1] % Q;
	for(i=1; i<N; i++) ifact[i] = ifact[i-1] * inv[i] % Q;
	for(i=1; i<N; i++){
		ifp[i][0] = 1;
		for(j=1; j<N; j++){
			ifp[i][j] = ifp[i][j-1] * ifact[i] % Q;
		}
	}
	dp[a-1][0] = 1;
	for(i=a; i<=b; i++){
		dp[i][0] = 1;
		for(j=1; j<=n; j++){
			dp[i][j] = dp[i-1][j];
			for(k=c; k<=d; k++){
				if(k*i > j) break;
				dp[i][j] = (dp[i][j] + dp[i-1][j-i*k]*fact[n-j+i*k]%Q * ifact[n-j]%Q * ifp[i][k]%Q * ifact[k]%Q)%Q;
			}
		}
	}
	
	printf("%lld\n", dp[b][n]);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
  ^