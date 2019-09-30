#include <cstdio>
#include <algorithm>
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
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
using namespace std;
typedef long double ld;
typedef long long int  lli;
typedef complex <double> P;
const double eps = 1e-11;
int vex[4]={1,0,-1,0};
int vey[4]={0,1,0,-1};
int x[1005],y[1005],c[1005];
int N;
bool C(double K){
	double mLx=-10000000,mRx=100000000;
	double mLy=-10000000,mRy=100000000;
	rep(i,N){
		mLx = max(x[i]-K/c[i],mLx);
		mRx = min(x[i]+K/c[i],mRx);
		mLy = max(y[i]-K/c[i],mLy);
		mRy = min(y[i]+K/c[i],mRy);

	}
	return  mLx<=mRx&&mLy<=mRy;
}
int main(){
	cin >> N;
	rep(i,N)cin >> x[i]>>y[i]>>c[i];
	double up=10000000000,lw=0,mid;
	rep(i,100){
		mid = (up+lw)/2;
		if(C(mid))up = mid;
		else lw = mid;
	}
	printf("%.10f\n",lw);
	}