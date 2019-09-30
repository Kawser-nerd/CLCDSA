#include<cstring>
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

typedef long long ll;
const int maxn = 900010,rhl = 1000000007;
int N,M,K; ll jie[maxn],inv[maxn],mi[maxn];

inline ll qsm(ll a,int b)
{
	ll ret = 1;
	for (;b;b >>= 1,(a *= a) %= rhl) if (b&1) (ret *= a) %= rhl;
	return ret;
}

inline int gi()
{
	char ch; int ret = 0,f = 1;
	do ch = getchar(); while (!(ch >= '0'&&ch <= '9')&&ch != '-');
	if (ch == '-') f = -1,ch = getchar();
	do ret = ret*10+ch-'0',ch = getchar(); while (ch >= '0'&&ch <= '9');
	return ret*f;
}

inline ll C(int n,int m) { if (n < m||m < 0) return 0; return jie[n]*inv[m]%rhl*inv[n-m]%rhl; }

int main()
{
	//freopen("H.in","r",stdin);
	//freopen("H.out","w",stdout);
	N = gi(); M = gi(); K = gi();
	jie[0] = mi[0] = 1;
	for (int i = 1;i <= N+M+K;++i)
	{
		mi[i] = mi[i-1]*3LL; while (mi[i] >= rhl) mi[i] -= rhl;
		jie[i] = jie[i-1]*(ll)i; if (jie[i] >= rhl) jie[i] %= rhl;
	}
	inv[N+M+K] = qsm(jie[N+M+K],rhl-2);
	for (int i = N+M+K;i;--i)
	{
		inv[i-1] = inv[i]*(ll)i;
		if (inv[i-1] >= rhl) inv[i-1] %= rhl;
	}
	ll sum = 1,ans = 0;
	for (int i = 0;i <= M+K;++i)
	{
		ll tm = C(N+i-1,i)*mi[M+K-i]%rhl;
		ans += tm*sum%rhl; if (ans >= rhl) ans %= rhl;
		sum <<= 1; if (sum >= rhl) sum -= rhl;
		sum -= C(i,i-K)+C(i,M); while (sum < 0) sum += rhl;
	}
	cout << ans << endl;
	return 0;
}