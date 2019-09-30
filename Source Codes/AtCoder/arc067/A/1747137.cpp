#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=j;i>=k;i--)
#define LL long long
using namespace std ;
inline int read() {
	int x = 0 , f = 1 ;
	char ch = getchar() ;
	while(ch<'0'||ch>'9') { if(ch=='-') f = -1 ; ch = getchar() ; }
	while(ch>='0'&&ch<='9') { x = x * 10+ch-48 ; ch = getchar() ; }
	return x * f ;
}

const int N = 1011, mod = 1e9+7;

int n;
int f[1011],ans;

int main() {
	scanf("%d",&n);
	For(i, 2, n) {
		int x = i;
		for(int j=2; j*j<=i; j++) 
			while( x%j==0 ) f[j]++,x/=j; 
		if(x!=1) f[x]++;
	}
	ans = 1;
	For(i, 2, 1000) 
		ans = 1ll*ans*(f[i]+1)%mod;
	printf("%d\n",ans);
	return 0;
}