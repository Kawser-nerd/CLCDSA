#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

long double x, y, z, vx, vy, vz;
int n;

void read() {
	int i;
	long a, b, c, d, e, f;
	x = y = z = vx = vy = vz = 0;
	
	scanf("%d", &n);
	
	for (i=0; i<n; i++) {
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
		x += a;
		y += b;
		z += c;
		vx += d;
		vy += e;
		vz += f; 
	}
	
	x /= n; y /= n; z /= n; vx /= n; vy /= n; vz /= n;
}

long double get_time() {
	if (vx*vx+vy*vy+vz*vz == 0) {
		return 0;
	}
	
	return -(vx*x+vy*y+vz*z)/(vx*vx+vy*vy+vz*vz);
}

long double dist(long double t) {
	return sqrt( (vx*t+x)*(vx*t+x) + (vy*t+y)*(vy*t+y) + (vz*t+z)*(vz*t+z) );
}

void single_case() {
	long double t;
	
	read();
	t = get_time();
	if (t < 0) t = 0;
	
	printf("%0.8Lf %0.8Lf\n", dist(t), t); 
}

int main()
{
	int c, i;
	
	scanf("%d\n", &c);
	
	for (i=1; i<=c; i++) {
		printf("Case #%d: ", i);
		single_case();
	}
	
	return 0; 
}