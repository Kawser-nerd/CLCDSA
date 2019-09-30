#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int mod = 924844033, maxn = 2010;
int n, k, fac[maxn], a[maxn], cnt;
ll f[maxn][maxn][2][2];
bool vis[maxn];
int main()
{
	scanf("%d %d", &n, &k);
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	for(int i = 1; i <= n; i++) if(!vis[i])
		for(int j = i; j <= n; j += k) vis[j] = 1, a[++cnt] = j;
	f[0][0][0][0] = 1;
	a[0] = -1e9;
	for(int i = 1; i <= n; i++) {
		f[i][0][0][0] = 1;
		for(int j = 1; j <= i; j++) {
			f[i][j][0][0] = (f[i - 1][j][1][0] + f[i - 1][j][0][0] + (a[i] - a[i - 1] == k) * f[i - 1][j - 1][0][0]) % mod;
			f[i][j][0][1] = (a[i + 1] - a[i] == k) * (f[i - 1][j - 1][1][0] + f[i - 1][j - 1][0][0]) % mod;
			f[i][j][1][0] = (f[i - 1][j][0][1] + f[i - 1][j][1][1] + (a[i] - a[i - 1] == k) * f[i - 1][j - 1][0][1]) % mod;
			f[i][j][1][1] = (a[i + 1] - a[i] == k) * (f[i - 1][j - 1][0][1] + f[i - 1][j - 1][1][1]) % mod;
		}
	} 
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		int sum = (f[n][i][0][0] + f[n][i][0][1] + f[n][i][1][0] + f[n][i][1][1]) % mod;
		if(i & 1) ans = (ans - 1ll * sum * fac[n - i] % mod + mod) % mod;
			else ans = (ans + 1ll * sum * fac[n - i] % mod) % mod;
	}
	printf("%d\n", ans);
	return 0;
}