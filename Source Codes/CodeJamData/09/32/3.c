#include <stdio.h>
#include <math.h>
#define ZERO 0.000000001

double absolute(double x) {
	return x < 0.0 ? -x : x;
}

int main() {
	int t, T, n, i;
	double x, y, z, vx, vy, vz, cx, cy, cz, cvx, cvy, cvz, tmin, tmp;

	scanf("%d", &T);

	for(t = 1; t <= T; t++) {
		scanf("%d", &n);
		cx = cy = cz = cvx = cvy = cvz = 0.0;
		for(i = 0; i < n; i++) {
			scanf("%lf %lf %lf %lf %lf %lf", &x, &y, &z, &vx, &vy, &vz);
			cx += x; cy += y; cz += z;
			cvx += vx; cvy += vy; cvz += vz;
		}
		cx /= n; cy /= n; cz /= n;
		cvx /= n; cvy /= n; cvz /= n;
		tmp = cvx*cvx+cvy*cvy+cvz*cvz;
		if(absolute(tmp) < ZERO)
			tmin = ZERO;
		else
			tmin = -(cx*cvx+cy*cvy+cz*cvz)/tmp;
		if(tmin < ZERO) {
			tmin = ZERO;
			x = cx; y = cy; z = cz;
		} else {
			x = cx + cvx*tmin;
			y = cy + cvy*tmin;
			z = cz + cvz*tmin;
		}
		printf("Case #%d: %.8lf %.8lf\n", t, sqrt(x*x + y*y + z*z), tmin);
	}
	return 0;
}