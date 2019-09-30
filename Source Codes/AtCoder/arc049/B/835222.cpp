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
struct Area{
	double lx,ly,rx,ry;
};
pair<Area,bool> mul (Area A,Area B){
	Area C ={
		max(A.lx,B.lx),
		max(A.ly,B.ly),
		min(A.rx,B.rx),
		min(A.ry,B.ry)};
	//printf("%f,%f,%f,%f\n",C.lx,C.ly,C.rx,C.ry);
	if(C.lx>C.rx|| C.ly>C.ry) {
		return make_pair(C,false);
	}
	//printf("true\n");
	return make_pair(C,true);
}
vector<double>x(1005),y(1005),m(1005);
int N;
bool C(double K){
		Area a ={
			x[0]-K/m[0],
			y[0]-K/m[0],
			x[0]+K/m[0],
			y[0]+K/m[0]
		};
	rep(i,N){
		Area b = {
			x[i]-K/m[i],
			y[i]-K/m[i],
			x[i]+K/m[i],
			y[i]+K/m[i]
		};
		a = mul(a,b).first;
		if(!mul(a,b).second)return false;
	}
	//cout <<"K"<<  K << endl;
	return true;
}
int main(){
	cin >> N;
	rep(i,N)cin >> x[i]>>y[i]>>m[i];
	double up = 10000000000;
	double low = 0;
	double mid;
	rep(i,200){
		mid = (up+low)/2;
		///printf("%f",mid);
		if(C(mid))up = mid;
		else low = mid;
	}

	printf("%.10f\n",low);
}