#include<stdio.h>
#include <math.h>

#define MAXN 505
#define SN 504
#define MINF 0.00000001

int main(){
	int t, i, j, n;
	double x[MAXN], y[MAXN], z[MAXN], vx[MAXN], vy[MAXN], vz[MAXN];
	long double d1, d2, tm, dm;
	scanf("%d", &t);
//	printf("Case #1: %.8Lf\n", dm);
	for(i = 1; i <= t; ++i){
		scanf("%d", &n);
		for(j = 0; j < n; ++j)
			scanf("%lf%lf%lf%lf%lf%lf", &(x[j]),&(y[j]),&(z[j]),&(vx[j]),&(vy[j]),&(vz[j]));
		x[SN] = y[SN] = z[SN] = vx[SN] = vy[SN] = vz[SN] =0.0;
		for(j = 0; j < n; ++j){
			x[SN] +=x[j];
			y[SN] +=y[j];
			z[SN] +=z[j];
			vx[SN] +=vx[j];
			vy[SN] +=vy[j];
			vz[SN] +=vz[j];
		}
		d1 = x[SN] * vx[SN] + y[SN] * vy[SN] + z[SN] * vz[SN];
		d2 = vx[SN] * vx[SN] + vy[SN] * vy[SN] + vz[SN] * vz[SN];
		if (d2 > MINF )
			tm = (-1.0) * d1 /d2;
		else
			tm = 0.0;
		if (tm < MINF)
			tm = 0.0;
		dm = (x[SN] + tm * vx[SN]) *(x[SN] + tm * vx[SN]);
		dm += (y[SN] + tm * vy[SN]) *(y[SN] + tm * vy[SN]);
		dm += (z[SN] + tm * vz[SN]) *(z[SN] + tm * vz[SN]);
		dm = sqrt(dm/ (n *n));
		printf("Case #%d: %.8Lf %.8Lf\n",i, dm, tm);
	}
}