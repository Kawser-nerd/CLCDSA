#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=j;i>=k;i--)
#define LL long long
using namespace std ;

inline LL read() {
	LL x = 0 , f = 1 ;
	char ch = getchar() ;
	while(ch<'0'||ch>'9') { if(ch=='-') f = -1 ; ch = getchar() ; }
	while(ch>='0'&&ch<='9') { x = x * 10+ch-48 ; ch = getchar() ; }
	return x * f ;
}

const int N = 2e5+11;
int n;
int a[N];
LL ans;
LL L[N],R[N];

int main() {
	n=read();
	For(i, 1, n) a[i]=read();
	For(i, 1, n) L[i]=L[i-1]+a[i];
	Dow(i, n, 1) R[i]=R[i+1]+a[i];
	ans = 1e18;
	For(i, 1, n-1) 
		ans = min(ans,abs(L[i]-R[i+1]));
	printf("%lld\n",ans);
}