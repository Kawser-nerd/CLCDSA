
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define EPS (1E-11)
#define EQ(x,y) (fabs((x)-(y)) <= EPS)
#define LT(x,y) ((x)+EPS < (y))
#define GT(x,y) LT(y,x)
#define LE(x,y) (!GT(x,y))
double part(double R, double x1, double x2){
	double y1 = sqrt(R*R-x1*x1);
	double y2 = sqrt(R*R-x2*x2);
	return R*R*(acos(x1/R)- acos(x2/R))/2.+ x2*y2/2.0 - x1*y1/2.0;
}
double calc_area(double R, double B, double G){
	double ans = 0.0;
	double series_len = 2*B+G;
	int num = ceil(R/series_len);
	for(int i=0; i<num; i++){
		double y1 = series_len * i;
		double y2 = y1 + B;
		double y3 = y2 + G;
		double y4 = y3 + B;
		int pnum = 0;
		if(LT(y4, R))
			pnum = (int)floor(sqrt(R*R-y4*y4)/ series_len);
		ans += G*G*pnum;
		for(int j=pnum;;j++){
			double x1 = series_len * j;
			double x2 = x1 + B;
			double x3 = x2 + G;
			double x4 = x3 + B;
			if(LE(y3*y3+x3*x3, R*R)){
				ans += G*G;
			}else if(LE(R*R, y2*y2+x2*x2)){
				break;
			}else{
				bool f1 = LE(R*R, y3*y3 + x2*x2);
				bool f2 = LE(R*R, y2*y2 + x3*x3);
				if(f1){
					if(f2){
						double xa = sqrt(R*R-y2*y2);
						ans += part(R, x2, xa) - (xa-x2)*y2;
					}else{
						ans += part(R, x2, x3) - (x3-x2)*y2;
					}
				}else{
					if(f2){
						ans += part(R, y2, y3) - x2 * (y3-y2);
					}else{
						double xb = sqrt(R*R-y3*y3);
						ans += (y3-y2)*(xb-x2) + part(R, xb, x3) - (x3-xb)*y2;
					}
				}
			}
		}
	}
	return 4.0 * ans;
}
double calc(double f, double R, double t, double r, double g){
	double tot = R*R*M_PI;
	double band = r+f;
	double gap = g-2*f;
	double circle = R - t - f;
	if(LE(gap, 0.0) || LE(circle, 0.0) || LE(circle, band))
		return 1.0;
	return 1.0-calc_area(circle, band, gap)/tot;
}
int main(void){
	int cases;
	cin >> cases;
	for(int case_no=1; case_no <= cases; case_no++){
		double f, R, t, r, g;
		cin >> f >> R >> t >> r >> g;
		double ans = calc(f, R, t, r, g);
		cout << "Case #"<<case_no<<": "<<fixed << setprecision(6) << ans << endl;
	}
	return 0;
}
