#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main(){
	int N; scanf("%d", &N);
	for(int k=1; k<=N; k++){
		double f, R, t, r, g;
		scanf("%lf %lf %lf %lf %lf", &f, &R, &t, &r, &g);
		double A = M_PI*R*R;
		r+=f; g-=2*f; R-=t+f;
		if(g<1e-9){
			printf("Case #%d: 1.000000\n", k); continue;
		}
		double P=0.;
		for(double x=r; x<R; x+=g+2*r)for(double y=r; sqrt(x*x+y*y)<R; y+=g+2*r){
			double x1=x, y1=y, x2=x+g, y2=y+g;
			if(sqrt(x2*x2+y2*y2)<R){P+=g*g;continue;}
			if(x2 < y2){
				double h=x2; x2=y2; y2=h;
				h=x1; x1=y1; y1=h;
			}
			double c, d;
			if(y2 > R-1e-9)c=x1;
			else c = sqrt(R*R - y2*y2);
			d = sqrt(R*R - y1*y1);
			if(c < x1)c=x1; 
			if(d > x2)d=x2;
			P += (c-x1)*g;
			P += -c*sqrt(R*R-c*c)/2. + d*sqrt(R*R-d*d)/2. + R*R*(asin(d/R)/2. - asin(c/R)/2.) + (c-d)*y1;
		}
		P = 1. - P/(A/4.);
		printf("Case #%d: %.6lf\n", k, P);
	}
}
