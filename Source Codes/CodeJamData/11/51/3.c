#include<stdio.h>

int a[128],b[128],x1[128],x2[128];
int w,U,L,g;

double area(double x) {
	double ret=0;
	double y1=a[0],y2=b[0],x0=0;
	for(int i=1,j=1;i<L && j<U;) {
		if (x1[i]>x && x2[j]>x) {
			double y3=(a[i]-a[i-1])/(double)(x1[i]-x1[i-1])*(x-x1[i-1])+a[i-1];
			double y4=(b[j]-b[j-1])/(double)(x2[j]-x2[j-1])*(x-x2[j-1])+b[j-1];
			ret+=(y4-y3+y2-y1)*(x-x0)*0.5;
			break;
		} else if (x1[i]<x2[j]) {
			double y3=a[i];
			double y4=(b[j]-b[j-1])/(double)(x2[j]-x2[j-1])*(x1[i]-x2[j-1])+b[j-1];
			ret+=(y4-y3+y2-y1)*(x1[i]-x0)*0.5;
			y2=y4,y1=y3,x0=x1[i];
			i++;
		} else {
			double y3=(a[i]-a[i-1])/(double)(x1[i]-x1[i-1])*(x2[j]-x1[i-1])+a[i-1];
			double y4=b[j];
			ret+=(y4-y3+y2-y1)*(x2[j]-x0)*0.5;
			y2=y4,y1=y3,x0=x2[j];
			j++;
		}
	}
	return ret;
}

int main() {
	int N,cs=0;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d %d %d",&w,&L,&U,&g);
		for(int i=0;i<L;i++) scanf("%d %d",&x1[i],&a[i]);
		for(int i=0;i<U;i++) scanf("%d %d",&x2[i],&b[i]);
		double A=area(w);
//		printf("%lf %lf %lf\n",A,area(5),area(10));
		printf("Case #%d:\n",++cs);
		for(int i=1;i<g;i++) {
			double s=A/g*i,l=0,r=w;
			for(int i=0;r-l>1e-12 && i<100;i++) {
				if (area((l+r)/2)>s) r=(l+r)/2; else l=(l+r)/2;
			}
			printf("%.20lf\n",(l+r)/2);
		}
	}
	return 0;
}
