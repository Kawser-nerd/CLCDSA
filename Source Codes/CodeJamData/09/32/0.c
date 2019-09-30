#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double sqr(double x)
{
	return x*x;
}

int dblcmp(double x, double y)
{
	if (fabs(x-y)<1e-9) return 0;
	else if (x<y) return -1;
	else return 1;
}

int main()
{
	int v=0,V;
	int i,x,y,z,vx,vy,vz,n;

	for(scanf("%d",&V);V;V--) {
		v++;

		scanf("%d",&n);
		double X=0,Y=0,Z=0;
		double VX=0,VY=0,VZ=0;
		for(i=0;i<n;i++) {
			scanf("%d%d%d%d%d%d",&x,&y,&z,&vx,&vy,&vz);
			X+=x;
			Y+=y;
			Z+=z;
			VX+=vx;
			VY+=vy;
			VZ+=vz;
		}

		double t,d;

		double mm=(VX*VX+VY*VY+VZ*VZ);
		if (fabs(mm)<1e-9) {
			printf("Case #%d: %.8lf 0.00000000\n", v, sqrt(sqr(X)+sqr(Y)+sqr(Z))/n);
			continue;
		}

		t=-(VX*X+VY*Y+VZ*Z)/mm;
		if (dblcmp(t,0)==-1) {
			t=0;
		}
		else if (dblcmp(VX*X+VY*Y+VZ*Z,0)==0) t=0;

		d=sqr(X+t*VX)+sqr(Y+t*VY)+sqr(Z+t*VZ);
		d=sqrt(d)/n;

		printf("Case #%d: %.8lf %.8lf\n", v, d, t);
	}

	return 0;
}
			
