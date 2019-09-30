#include<cstdio>
#include<map>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)
#define REPSZ(i,v) REP(i,SZ(v))

typedef struct P {
	double x,y;
	P() {}
	P(double x,double y):x(x),y(y) {}
} P;
P operator-(const P &A,const P &B) { return P(A.x-B.x,A.y-B.y); }
double operator^(const P &A,const P &B) { return A.x*B.y-A.y*B.x; }

double f,R,t,r,g;

double sdarea(const P &A,const P &B,const P &C) {
	return (B-A)^(C-A);
}

double area(const P &A,const P &B,const P &C) {
	return fabs(sdarea(A,B,C))/2;
}

double calc(const P &A,const P &B,const P &C,double z) {
	P O(0,0);
	double frac=fabs(atan2(B.y,B.x)-atan2(C.y,C.x))/2/M_PI;
//	printf("ang = %lf, z= %lf => %lf-%lf-%lf\n",frac*360,z,frac*M_PI*z*z,area(O,A,B),area(O,A,C));
	return frac*M_PI*z*z-area(O,A,B)-area(O,A,C);
}

bool test(int x,int y) {
	double hx=x*(2*r+g)+r+g;
	double hy=y*(2*r+g)+r+g;
	return hx*hx+hy*hy<=(R-t)*(R-t);
}

void run(int casenr) {
	scanf("%lf%lf%lf%lf%lf",&f,&R,&t,&r,&g);
	double z=R-t-f;
	double areafull=2*f<=g?(g-2*f)*(g-2*f):0;
	double num=0,den=M_PI*R*R;
	for(int x=0;x*(2*r+g)<=R;++x) {
		int ly,hy;
		if(!test(x,0)) ly=-1,hy=0; else ly=0,hy=1;
		while(test(x,hy)) ly=hy,hy+=hy;
		while(ly+1<hy) {
			int my=(ly+hy)/2;
			if(test(x,my)) ly=my; else hy=my;				
		}
		int y=hy;
		
		num+=y*areafull;
//		printf("%d * %lf\n",y,areafull);
		for(;;++y) {
			double x1=x*(2*r+g)+r+f;
			double x2=x*(2*r+g)+r+g-f;
			double y1=y*(2*r+g)+r+f;
			double y2=y*(2*r+g)+r+g-f;

//			printf("%d %d\n",x,y);
			if(x1>=x2||y1>=y2||x1*x1+y1*y1>=z*z) break;
	
	
			if(x1*x1+y2*y2>=z*z&&y1*y1+x2*x2>=z*z) {
				double x3=sqrt(z*z-y1*y1);
				double y3=sqrt(z*z-x1*x1);
	//			printf("%lf %lf %lf / %lf %lf %lf\n",x1,x3,x2,y1,y3,y2);
//				printf("a %lf\n",calc(P(x1,y1),P(x3,y1),P(x1,y3),z));
				num+=calc(P(x1,y1),P(x3,y1),P(x1,y3),z);
			} else if(x1*x1+y2*y2>=z*z) {
				double y3=sqrt(z*z-x2*x2);
				double y4=sqrt(z*z-x1*x1);
				assert(y1<=y3&&y3<=y4&&y4<=y2);
//				printf("b %lf+%lf\n",(x2-x1)*(y3-y1),calc(P(x1,y3),P(x1,y4),P(x2,y3),z));
				num+=(x2-x1)*(y3-y1);
				num+=calc(P(x1,y3),P(x1,y4),P(x2,y3),z);
			} else if(y1*y1+x2*x2>=z*z) {
				double x3=sqrt(z*z-y2*y2);
				double x4=sqrt(z*z-y1*y1);
//				printf("c %lf+%lf\n",(y2-y1)*(x3-x1),calc(P(x3,y1),P(x4,y1),P(x3,y2),z));
				num+=(y2-y1)*(x3-x1);
				num+=calc(P(x3,y1),P(x4,y1),P(x3,y2),z);
			} else {
				double x3=sqrt(z*z-y2*y2);
				double y3=sqrt(z*z-x2*x2);
//				printf("%lf %lf %lf / %lf %lf %lf\n",x1,x3,x2,y1,y3,y2);
//				assert(y1<=y3&&y3<=y2&&x1<=x3&&x3<=x2);
//				printf("d %lf+%lf\n",(x2-x1)*(y2-y1)-(x2-x3)*(y2-y3),calc(P(x3,y3),P(x2,y3),P(x3,y2),z));
				num+=(x2-x1)*(y2-y1)-(x2-x3)*(y2-y3);
				num+=calc(P(x3,y3),P(x2,y3),P(x3,y2),z);
			}
		}
	}
	printf("Case #%d: %.10lf\n",casenr,1.0-4*num/den);
}

int main() {
	int n; scanf("%d",&n);
	FORE(i,1,n) run(i);
	return 0;
}
