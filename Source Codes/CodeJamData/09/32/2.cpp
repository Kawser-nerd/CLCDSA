#include<iostream>
#include<cmath>
using namespace std;

const double eps = 1e-10;

int N;
double sum_x, sum_y, sum_z, sum_vx, sum_vy, sum_vz;
double cx,cy,cz;
double x, y, z, vx, vy, vz;
double sqr(double a){return a*a;}

double F(double t) {
	return sqrt(sqr(x+vx*t)+sqr(y+vy*t)+sqr(z+vz*t));
}

int run() {
	scanf("%d", &N);
	sum_x=sum_y=sum_z=sum_vx=sum_vy=sum_vz=0;
	for(int i=0;i<N;++i) {
		cin>>x>>y>>z>>vx>>vy>>vz;
		sum_x+=x;sum_y+=y;sum_z+=z;
		sum_vx+=vx;sum_vy+=vy;sum_vz+=vz;
	}
	
	x=sum_x/N, y=sum_y/N, z=sum_z/N;
	
	if(fabs(sum_vx)<=eps && fabs(sum_vy)<=eps && fabs(sum_vz)<=eps) {
		printf("%.7lf %.7lf\n", sqrt(x*x+y*y+z*z),0);
		return 1;
	}
	
	vx=sum_vx/N; vy=sum_vy/N; vz=sum_vz/N;
	double lo = 0, hi = 100000000, m1, m2, d1, d2;
	for(int ii=0;ii<100000;++ii) {
		m1 = (lo*2+hi)/3;
		m2 = (lo+hi*2)/3;
		d1=F(m1); d2=F(m2);
		if(d1 < d2) hi = m2;
		else lo = m1;
	}
	
	printf("%.7lf %.7lf\n", F(lo), lo);
}

int main() {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	
	int test; scanf("%d",&test);
	for(int no=1;no<=test;++no) {
		printf("Case #%d: ",no);
		run();
	}
}
