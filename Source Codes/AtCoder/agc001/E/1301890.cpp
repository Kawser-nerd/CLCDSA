#include <cstdio>

const int N = 200100;
const int MOD = 1000000007;

int a[N], b[N];
int dp[4010][4010];
int val[4010][4010];
int val2[4010][4010];
long long fat[8010], inv[8010];


long long fpow(long long a, long long b){
	long long c = 1;
	for(;b;b>>=1, a=(a*a)%MOD)if(b&1)c=(c*1ll*a)%MOD;
	return c;
}

void calcfat(int qtd){
	fat[0]=1;
	for(int i = 1; i <= qtd; i++){
		fat[i]=(fat[i-1]*1ll*i)%MOD;
	}
}

void calcinv(int qtd){
	inv[0]=1;
	for(int i = 1; i <= qtd; i++){
		inv[i]=fpow(fat[i],MOD-2);
	}
}
long long comb(int a, int b){
	return (((fat[2*a+2*b]*inv[2*a])%MOD)*inv[2*b])%MOD;
}

int main(){
	int n;
	scanf("%d", &n);
	calcfat(8001);
	calcinv(8001);
	long long ans = 0;
	for(int i = 0; i <= 8001; i++){
		//printf("%lld ",fat[i]);
	}
	//puts("");
	for(int i = 0; i < n; i++){
		int a, b;
		scanf("%d %d",&a,&b);
		ans = (ans - comb(a,b) + MOD) % MOD;
		//printf("%lld\n",ans);
		val2[2001+a][2001+b]++;
		val[2001-a][2001-b]++;
	}
	//printf("%lld\n",ans);
	for(int i = 1; i <= 4001; i++){
		for(int j = 1; j <= 4001; j++){
			dp[i][j]=((dp[i-1][j]+dp[i][j-1]) % MOD + val[i][j])%MOD;
			if(i>2001 && j>2001 && val2[i][j]>0){
				ans+=(val2[i][j]*1ll*dp[i][j])%MOD;
				ans%=MOD;
			}

			dp[i][j]%=MOD;
		}
	}
	ans = (ans *1ll* fpow(2,MOD-2))%MOD;
	printf("%lld\n",ans);

}