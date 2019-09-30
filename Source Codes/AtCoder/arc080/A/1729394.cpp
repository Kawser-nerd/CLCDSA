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
int a,b,c,d;


int main() {
	n=read();
	For(i, 1, n) {
		x=read();
		if(x%4==0) a++;
		else if(x%2==0) b++;
		else c++;
	}
	if(b) c++;
	c--;
	if(a-c<0) puts("No");
	else puts("Yes");
}