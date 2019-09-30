#include <stdio.h>
#include <math.h>
int n,i;
double pi;
int incircle(double r, double x, double y) {
	return x*x+y*y < r*r;
}
double chord(double r, double h) {
	return (r * r * acos(h/r) - h * sqrt (r*r - h*h))/2.;
}
double case0(double r, double x, double y, double a) {
	double x1 = sqrt(r * r - y * y);
//	printf("case 0: r %lf: %lf %lf %lf %lf, res %lf\n",r,x,x1,y,a,chord(r,x));// - chord(r,x1) - y*(x1-x));
	return chord(r,x) - chord(r,x1) - y*(x1-x);
}
double case2(double r, double x, double y, double a) {
	return chord(r,x) - chord(r,x+a) - a * y;
}
double case1(double r, double x, double y, double a) {
	return case2(r,y,x,a);
}
double case3(double r, double x, double y, double a) {
	double x1 = sqrt(r * r - (y+a) * (y+a));
	return a*(x1-x) + case2(r,x1,y,x+a-x1);
}
int main() {
	pi = atan(1.0)*4;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		double f,R,t,r,g,area,holes = 0.0,step;
		int fullholes = 0;
		scanf("%lf%lf%lf%lf%lf",&f,&R,&t,&r,&g);
		r += f;
		g -= 2*f;
		t = R - t - f;
		if(t <= 0. || g <= 0.) {
			printf("Case #%d: %.6lf\n",i+1,1.);
			continue;
		}
		area = pi * R * R / 4.0;
//		printf("area: %lf\n",area);
		holes = 0.0;
		double j,k;
		int j1,k1;
		step = 2*r+g;
		for(j1=0,j=r;j<t;j=r+ ++j1*step) {
			for(k1=0,k=r;k<t;k=r+ ++k1*step) {
				if(incircle(t,j+g,k+g)) {
					fullholes++;
				} else if(!incircle(t,j,k)) {
//					break;
				} else {
					int in1 = incircle(t,j,k+g);
					int in2 = incircle(t,j+g,k);
					switch(in1+in2+in2) {
					case 0: holes += case0(t,j,k,g); break;
					case 1: holes += case1(t,j,k,g); break;
					case 2: holes += case2(t,j,k,g); break;
					case 3: holes += case3(t,j,k,g); break;
					}
				}
			}
		}
		printf("Case #%d: %lf\n",i+1,(area-holes-g*g*fullholes)/area);
	}
	return 0;
}
