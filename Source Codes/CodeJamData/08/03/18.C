#include <stdio.h>
#include <math.h>
const double PI=2*acos(0);

int main() {
	double f,R,r,t,g,res;
	int i,n;
	scanf("%d",&n);
	for (i=0; i<n; ++i) {
		scanf("%lf %lf %lf %lf %lf",&f,&R,&t,&r,&g);
		if (2*f>=g || R-t-f<0) res=1.0;
		else {
			double l,u,ar=0;
			for (l=r; l<R-t; l+=g+2*r) for (u=r; u*u+l*l<(R-t)*(R-t); u+=g+2*r) {
				double rt=(R-t-f)*(R-t-f);
					double l2=l+f,r2=l+g-f,b2=u+f,u2=u+g-f;
					double lx,rx,ux,ar2=0;
					if (r2*r2+u2*u2<=rt) { ar+=pow(g-2*f,2); continue; }
					else if (l2*l2+b2*b2>=rt) continue;
					if (l2*l2+u2*u2<rt) {
						lx=sqrt(rt-u2*u2);
						if (lx>l2) ar2+=(lx-l2)*(u2-b2);
						// upper cut
					} else {
						lx=l2;
						// left cut
					}
					if (r2*r2+b2*b2<rt) {
						ux=sqrt(rt-r2*r2);
						if (ux>b2) ar2+=(r2-lx)*(ux-b2);
						rx=r2;
						// right cut
					} else {
						ux=b2;
						rx=sqrt(rt-b2*b2);
						// bottom cut
					}
					//printf("ar2 vs. pow(g-2*f): %.6lf %.6lf; rx=%.6lf, sqrt(rt)=%.6lf\n",ar2,pow(g-2*f,2),rx,sqrt(rt));
					double asinrx=(rx*rx>=rt ? 1.0 : rx/sqrt(rt)),sqrx=(rx*rx>=rt ? 0.0 : rt-rx*rx);
					double asinlx=(lx*lx>=rt ? 1.0 : lx/sqrt(rt)),sqlx=(lx*lx>=rt ? 0.0 : rt-lx*lx);
					double cr=rt/2*asin(asinrx)+rx/2*sqrt(sqrx) - (rt/2*asin(asinlx)+lx/2*sqrt(sqlx));
					double st=ux*(rx-lx);
					ar2+=cr-st;
					//printf("ar2 vs. pow(g-2*f): %.6lf %.6lf\n",ar2,pow(g-2*f,2));
					ar+=ar2;
			}
			res=1-4*ar/(PI*R*R);
			if (res<0) res=0;
		}
		printf("Case #%d: %.6lf\n",i+1,res);
	}
	return 0;
}
