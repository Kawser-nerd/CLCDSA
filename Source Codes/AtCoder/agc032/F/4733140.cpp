#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define SIZE 1010101
ll inv[SIZE + 1];
ll kai[SIZE + 1];
ll invkai[SIZE + 1];
void invinit()
{
	inv[1] = 1;
	for (int i = 2; i <= SIZE; i++)
	{
		inv[i] = mod - (mod / i)*inv[mod%i] % mod;
	}
	kai[0] = invkai[0] = 1;
	for (int i = 1; i <= SIZE; i++)
	{
		kai[i] = kai[i - 1] * i%mod;
		invkai[i] = invkai[i - 1] * inv[i] % mod;
	}
}
ll com(ll a, ll b)
{
	if (b < 0 || a < b)return 0;
	return (invkai[b] * invkai[a - b]) % mod*kai[a] % mod;
}
ll dp[1010101][3];
int main()
{
	ll n;
	scanf("%lld", &n);
	invinit();
	dp[1][0] = 3;
	for (int i = 2; i <= n + 10; i++)
	{
		for (int j = 0; j < 3; j++)dp[i][j] = (dp[i - 1][(j + 1) % 3] + dp[i - 1][(j + 2) % 3]) % mod;
	}
	ll r = 0;
	for (int k = 1; k <= n; k++)
	{
		ll s1 = com(n, k)*(n - 1) % mod*(dp[k][0] + dp[k][2]) % mod*k%mod;
		ll s2 = inv[k] * inv[k] % mod*inv[n] % mod*inv[n - 1] % mod;
		//printf("%lld %lld\n", s1, (n - 1)*n % mod*k%mod*k%mod);
		r = (r + s1*s2) % mod;
	}
	for (int i = 0; i < n + 1; i++)r = r*inv[3] % mod;
	printf("%lld\n", r);
}