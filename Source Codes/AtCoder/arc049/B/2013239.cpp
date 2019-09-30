#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

double search(double ans,int n,int m,double* x,double* y,double* c){
	if(m >= 65){
		return ans;
	}
	double xinf = -100000,yinf = -100000,xsup = 100000,ysup = 100000;
	for(int i = 0;i < n;i++){
		xinf = max(x[i] - ans/c[i],xinf);
		yinf = max(y[i] - ans/c[i],yinf);
		xsup = min(x[i] + ans/c[i],xsup);
		ysup = min(y[i] + ans/c[i],ysup);
	}
	double ans_2;
	if(xinf < xsup && yinf < ysup){
		ans_2 = ans - 100000000.0/pow(2,(double)m);
	}
	else{
		ans_2 = ans + 100000000.0/pow(2,(double)m);
	}
	return search(ans_2,n,m+1,x,y,c);
}

int main(){
	int n;
	cin >> n;
	double x[n],y[n],c[n];
	for(int i = 0;i < n;i++){
		cin >> x[i] >> y[i] >> c[i];
	}
	cout << fixed << setprecision(12) << search(100000000.0,n,0,x,y,c) << endl;
	return 0;
}