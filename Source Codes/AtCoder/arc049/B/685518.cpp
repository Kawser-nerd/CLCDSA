#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

bool hantei(vector<pair<int, int> >p, vector<int> c, double t,const int N) {
	double xL, xR,yL,yR;
	double xLmax = -1000000, xRmin = 1000000,yLmax=-1000000,yRmin=1000000;
	rep(i, 0, N) {
		xL = 1.0*p[i].first - t/c[i];
		xR = 1.0*p[i].first + t/c[i];
		if (xL > xLmax)xLmax = xL;
		if (xR < xRmin)xRmin = xR;
		yL =1.0* p[i].second - t/c[i];
		yR = 1.0*p[i].second + t/c[i];
		if (yL > yLmax)yLmax = yL;
		if (yR < yRmin)yRmin = yR;
	}
	if (xLmax <= xRmin && yLmax <= yRmin)return true;
	else return false;

}

int main() {
	int N; cin >> N;
	vector<pair<int, int> >p(N);
	vector<int> c(N);
	rep(i, 0, N) {
		cin >> p[i].first >> p[i].second >> c[i];

	}
	double left = 0;
	double right = 100000000000;
	double t = right;
	rep(i, 0, 200) {
		t = (right + left) / 2;
		if (hantei(p, c, t, N) == true)right = (right + left) / 2;
		else left=(right+left)/2;
	}
	cout <<setprecision(15)<< t << endl;
}