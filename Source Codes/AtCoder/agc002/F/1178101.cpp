#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
using namespace std;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
const int N=2010;
int f[N][N],fac[N*N],inv[N*N];
const int mod=1e9+7;
inline int C(int n,int m) {
	return 1LL*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
inline int qpow(int x,int y) {
	int ans=1;
	while (y) {
		if (y&1) ans=1LL*ans*x%mod;
		x=1LL*x*x%mod;y>>=1;
	}
	return ans;
}
int main() {
	int n=gi(),m=gi(),i,j;
	if (m==1) { puts("1"); return 0; }
	for (i=fac[0]=1;i<=m*n;i++) fac[i]=1LL*fac[i-1]*i%mod;
	inv[n*m]=qpow(fac[n*m],mod-2);
	for (i=n*m;i;i--) inv[i-1]=1LL*inv[i]*i%mod;m--;
	f[0][0]=1;
	for (i=1;i<=n;i++)
		for (j=0;j<=i;j++)
			f[i][j]=((j?f[i][j-1]:0)+(i==j?0:1LL*f[i-1][j]*C(j+i*m-1,m-1)))%mod;
	printf("%d\n",int(1LL*f[n][n]*fac[n]%mod));
	return 0;
}