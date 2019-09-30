#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include "math.h"
#include <complex>
#include <iomanip>
#define ifor(i,a,b) for (int i=(a);i<(b);i++)
#define rfor(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
using namespace std;
typedef long double ld;
typedef long long int  lli;
typedef complex <double> P;
const double eps = 1e-11;
int vex[4]={1,0,-1,0};
int vey[4]={0,1,0,-1};
lli ans;
lli mod = pow(10,9)+7;
lli x[200005];	
lli x_inv[200005];
lli cmb(lli a,lli b){
	return x[a]*x_inv[b]%mod*x_inv[a-b]%mod;
}
lli get_inv(lli x){
	lli m = mod-2;
	lli s = 1;
	while(m!=0){
		if(m&1)s=(s*x)%mod;
		x=(x*x)%mod;
		m>>=1;
	}
	return s;
}
int main(){
lli A,B,W,H;
cin >> H >> W >> A >> B;
x[0] = x_inv[0]=1; 
rep(i,W+H+3){
	x[i+1]=x[i]*(i+1)%mod;
	x_inv[i+1]=get_inv(x[i+1]);
}
lli ans = 0;
for(int i = 0;i<H-A;i++){
	ans +=cmb(i+B-1,B-1)*cmb(H-i+W-B-2,W-B-1);
	ans %=mod;
}
cout << ans<<endl;
}