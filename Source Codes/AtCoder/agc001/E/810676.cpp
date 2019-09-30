#include <cstdio>
#include <algorithm>

using namespace std;

#define N_MAX 200000
#define MOD 1000000007
#define INV2 500000004
#define AB_MAX 2000

typedef long long ll;



bool memoed[8001][4001];
int memo[8001][4001];
int comb(int n,int k){
	if(k == 0 || k == n) return 1;
	if(k > n-k)k = n-k;
	if(memoed[n][k]) return memo[n][k];
	memoed[n][k] = true;
	return memo[n][k] = (comb(n-1,k) + comb(n-1,k-1)) % MOD;
}



int n;
int a[N_MAX];
int b[N_MAX];
int dp[AB_MAX*2+1][AB_MAX*2+1];

#define DP(a,b) (dp[(a)+AB_MAX][(b)+AB_MAX])

int main(){
	scanf("%d",&n);
	int maxa = 0;
	int maxb = 0;
	for(int i = 0;i < n;i++){
		scanf("%d %d", &a[i], &b[i]);
		maxa = max(maxa, a[i]);
		maxb = max(maxb, b[i]);
		DP(-a[i],-b[i])++;
	}
	for(int aa=-maxa;aa<=maxa;aa++)
	for(int bb=-maxb;bb<=maxb;bb++){
		if(bb < maxb){ DP(aa,bb+1) += DP(aa,bb); DP(aa,bb+1) %= MOD; }
		if(aa < maxa){ DP(aa+1,bb) += DP(aa,bb); DP(aa+1,bb) %= MOD; }
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		ans += DP(a[i],b[i]);
		ans %= MOD;
		ans -= comb(2*a[i]+2*b[i],2*b[i]);
		if(ans < 0) ans += MOD;
		ans %= MOD;
	}
	ans = (int)(((ll)ans * (ll)INV2) % MOD);
	printf("%d\n", (int)ans);
	return 0;
}