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

const int N = 1e5+11;
int n,x,y,S;
int a[N];
inline bool cmp(int a,int b) {
	return a > b;
} 

int main() {
	n=read();
	For(i, 1, n) a[i]=read();
	sort(a+1,a+n+1,cmp); 
	For(i, 1, n-1) 
		if(a[i]==a[i+1]) {
			x = a[i];
			S = i+2;
			break;
		}
	For(i, S, n-1) 
		if(a[i]==a[i+1]) {
			y = a[i];
			break;
		}
	printf("%lld\n",1ll*x*y);
}