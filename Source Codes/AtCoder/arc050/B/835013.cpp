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
lli r,b,x,y;
bool C(lli K){
	lli R=r,B=b;
	R-=K;
	B-=K;
	if(R<0||B<0)return false;
	return(R/(x-1)+B/(y-1))>=K;
}
int main(){
	cin >> r >> b >> x >> y;
	lli u,l;
	u=pow(10,18);
	u++;
	l=-1;
	lli m;
	//cout << u<<endl;
	while(u-l>1){
		//printf("%d,%d,%d,%d",u,l,m);
		m=(u+l)/2;
		if(C(m)){
			l = m;
		}
		else u = m;
	}
	cout << l << endl;
}