//Zory-2019
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<bitset>
#include<vector>
#include<algorithm>
#include<iostream>
#include<deque>
// #include<unordered_map>
using namespace std;
int bin[40],lg[1<<21];
namespace mine
{
	typedef long long ll;
	#define double long double
	const int INF=0x3f3f3f3f;
	const ll LLINF=0x3f3f3f3f3f3f3f3fll;
	ll qread()
	{
		ll ans=0;char c=getchar();int f=1;
		while(c<'0' or c>'9') {if(c=='-') f=-1;c=getchar();}
		while('0'<=c and c<='9') ans=ans*10+c-'0',c=getchar();
		return ans*f;
	}
	void write(ll num)
	{
		if(num<0) {num=-num;putchar('-');}
		if(num>9) write(num/10);
		putchar('0'+num%10);
	}
	void writeln(int num){write(num);puts("");}
	#define FR first
	#define SE second
	#define MP make_pair
	#define pr pair<int,int>
	#define PB push_back
	#define vc vector
	void chmax(int &x,const int y) {x=x>y?x:y;}
	void chmin(int &x,const int y) {x=x<y?x:y;}
	const int MAX_N=2e3+10;
	const int MOD=1e9+7;
	void add(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;if(x<0) x+=MOD;}

	const int MAX_M=MAX_N*MAX_N;
	int fac[MAX_M],inv[MAX_M],facinv[MAX_M];
	int C(int n,int m) {if(n<m) return 0;return (ll)fac[n]*facinv[m]%MOD*facinv[n-m]%MOD;}
	int f[MAX_N][MAX_N];
	void main()
	{
		inv[1]=1;for(int i=2;i<MAX_M;i++) inv[i]=ll(MOD-MOD/i)*inv[MOD%i]%MOD;
		fac[0]=1;for(int i=1;i<MAX_M;i++) fac[i]=(ll)fac[i-1]*i%MOD;
		facinv[0]=1;for(int i=1;i<MAX_M;i++) facinv[i]=(ll)facinv[i-1]*inv[i]%MOD;

		int n=qread(),k=qread();
		if(k==1) {puts("1");return;}
		f[0][0]=1;
		for(int i=1;i<=n;i++) for(int j=0;j<=i;j++)
		{
			if(i>0) add(f[i][j],f[i-1][j]);
			if(j>0) add(f[i][j],(ll)f[i][j-1]*(n-j+1)%MOD*C(n-i+(k-1)*(n-j+1)-1,k-2)%MOD );
			// printf("f[%d][%d]=%d\n",i,j,f[i][j]);
		}
		printf("%d",f[n][n]);
	}
};
int main()
{
	srand(time(0));
	bin[0]=1;for(int i=1;i<=30;i++) bin[i]=bin[i-1]<<1;
	lg[1]=0;for(int i=2;i<(1<<21);i++) lg[i]=lg[i>>1]+1;
	mine::main();
}